#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <nlohmann/json.hpp>
#include "IExchangeSocket.hpp"
#include <chrono>
#include <algorithm>
#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

class BinanceSocket : public IExchangeSocket {
public:
    auto run_socket(DataStore &map,
                    const std::vector<std::string> &symbols,
                    std::vector<std::unique_ptr<IExchangeSocket>> &exchanges,
                    const int id) -> void override {

        if(symbols.empty()) return;

        auto uri = std::string{"wss://stream.binance.com:9443/stream?streams="};
        for(auto i = size_t{0}; i < symbols.size(); ++i) {
            uri += symbols[i] + "@bookTicker";
            if(i < symbols.size() - 1) uri += "/";
        }

        try {
            auto c = client{};
            c.clear_access_channels(websocketpp::log::alevel::all);
            c.init_asio();

            c.set_tls_init_handler([](websocketpp::connection_hdl) {
                auto ctx = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12_client);
                ctx->set_options(boost::asio::ssl::context::default_workarounds |
                                 boost::asio::ssl::context::no_sslv2 |
                                 boost::asio::ssl::context::no_sslv3 |
                                 boost::asio::ssl::context::single_dh_use);
                return ctx;
            });

            c.set_message_handler([&map, id](websocketpp::connection_hdl, client::message_ptr msg) {
                try {
                    auto j = nlohmann::json::parse(msg->get_payload());
                    if(!j.contains("data")) return;

                    const auto& data = j["data"];
                    auto symbol = data["s"].get<std::string>();
                    std::transform(symbol.begin(), symbol.end(), symbol.begin(), ::tolower);

                    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch()).count();

                    auto bid_p = DataPoint{};
                    bid_p.price = std::stod(data["b"].get<std::string>());
                    bid_p.exchange_name = "Binance";
                    bid_p.timestamp = now;

                    auto ask_p = DataPoint{};
                    ask_p.price = std::stod(data["a"].get<std::string>());
                    ask_p.exchange_name = "Binance";
                    ask_p.timestamp = now;

                    map.write_bid(id, symbol, bid_p);
                    map.write_ask(id, symbol, ask_p);
                } catch(...) { }
            });

            auto ec = websocketpp::lib::error_code{};
            auto con = c.get_connection(uri, ec);
            if(ec) {
                std::cerr << "Binance connect error: " << ec.message() << std::endl;
                return;
            }

            c.connect(con);
            c.run();
        } catch(const std::exception& e) {
            std::cerr << "Binance runtime error: " << e.what() << std::endl;
        }
    }
};
