#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <nlohmann/json.hpp>
#include "IExchangeSocket.hpp"

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

class KucoinSocket : public IExchangeSocket {
public:
    void run_socket(DataStore &map, const std::vector<std::string> &symbols,
                    std::vector<std::unique_ptr<IExchangeSocket>> &exchanges, const int id) override {

        if(symbols.empty()) return;

        client c;
        c.clear_access_channels(websocketpp::log::alevel::all);
        c.set_access_channels(websocketpp::log::alevel::connect);
        c.init_asio();

        c.set_tls_init_handler([](websocketpp::connection_hdl) {
            return websocketpp::lib::make_shared<boost::asio::ssl::context>(
                boost::asio::ssl::context::tlsv12_client
            );
        });

        websocketpp::connection_hdl hdl; 

        c.set_open_handler([&c, &hdl, &symbols](websocketpp::connection_hdl connection_hdl) {
            hdl = connection_hdl;

            for(const auto& symbol : symbols) {
                std::string pair = symbol; // Format is e.g. "BTC-USDT"
                std::string subscribe_msg = R"({
                    "id": "subscribe-level1-)" + pair + R"(",
                    "type": "subscribe",
                    "topic": "/market/ticker:" + pair + R"(",
                    "privateChannel": false,
                    "response": true
                })";
                c.send(hdl, subscribe_msg, websocketpp::frame::opcode::text);
            }
        });

        c.set_message_handler([&map, id](websocketpp::connection_hdl, client::message_ptr msg) {
            try {
                auto j = nlohmann::json::parse(msg->get_payload());
                if(j["type"] != "message" || j["subject"] != "trade.ticker") return;

                const auto& data = j["data"];
                std::string symbol = data["symbol"];
                std::transform(symbol.begin(), symbol.end(), symbol.begin(), ::tolower);
                double bid = std::stod(data["bestBid"].get<std::string>());
                double ask = std::stod(data["bestAsk"].get<std::string>());

                DataPoint bid_point;
                DataPoint ask_point;

                bid_point.price = bid;
                ask_point.price = ask;
                bid_point.exchange_name = "KuCoin";
                ask_point.exchange_name = "KuCoin";

                map.write_bid(id, symbol, bid_point);
                map.write_ask(id, symbol, ask_point);
            } catch (...) {
                std::cerr << "Failed to parse or update KuCoin data.\n";
            }
        });

        websocketpp::lib::error_code ec;
        client::connection_ptr con = c.get_connection("wss://ws-api.kucoin.com/endpoint", ec);
        if(ec) {
            std::cerr << "Connection failed: " << ec.message() << std::endl;
            return;
        }

        c.connect(con);
        c.run();
    }
};

