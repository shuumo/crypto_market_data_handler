#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <nlohmann/json.hpp>
#include "IExchangeSocket.hpp"

using json = nlohmann::json;
typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

class BinanceSocket : public IExchangeSocket {
public:
    void run_socket(DataStore &map, const std::vector<std::string> &symbols,
                    std::vector<std::unique_ptr<IExchangeSocket>> &exchanges, const int id) override {

        if (symbols.empty()) return;

        std::string uri = "wss://stream.binance.com:9443/stream?streams=";
        for (size_t i = 0; i < symbols.size(); ++i) {
            uri += symbols[i] + "@bookTicker";
            if (i < symbols.size() - 1) uri += "/";
        }

        client c;
        c.clear_access_channels(websocketpp::log::alevel::all);
        c.set_access_channels(websocketpp::log::alevel::connect);
        c.init_asio();

        c.set_tls_init_handler([](websocketpp::connection_hdl) {
            return websocketpp::lib::make_shared<boost::asio::ssl::context>(
                boost::asio::ssl::context::tlsv12_client
            );
        });

        c.set_message_handler([&map, id](websocketpp::connection_hdl, client::message_ptr msg) {
            try {
                auto j = json::parse(msg->get_payload());
                //std::cout << msg->get_payload() << std::endl;
                const auto& data = j["data"];
                std::string symbol = data["s"];
                std::transform(symbol.begin(), symbol.end(), symbol.begin(), ::tolower);
                double bid = std::stod(data["b"].get<std::string>());
                double ask = std::stod(data["a"].get<std::string>());

                DataPoint bid_point;
                bid_point.price = bid;
                DataPoint ask_point;
                ask_point.price = ask;
                //std::cout << "This threads id is: " << id << '\n';
                map.write_bid(id, symbol, bid_point);
                map.write_ask(id, symbol, ask_point);
            } catch (...) {
                std::cerr << "Failed to parse or update data.\n";
            }
        });

        websocketpp::lib::error_code ec;
        client::connection_ptr con = c.get_connection(uri, ec);
        if (ec) {
            std::cerr << "Connection failed: " << ec.message() << std::endl;
            return;
        }

        c.connect(con);
        c.run();
    }
};

