#pragma once

#include <json.hpp>
using json = nlohmann::json;

#include <vector>
#include <string>
using namespace std;

namespace binance {
  namespace types {
    struct CancelOrderResponse {
      string symbol;
      long order_id;
      string client_order_id;
      string orig_client_order_id;
    };

    void to_json(json& j, const CancelOrderResponse& t) {
      j = json{
        { "symbol", t.symbol },
        { "orderId", t.order_id },
        { "clientOrderId", t.client_order_id },
        { "origClientOrderId", t.orig_client_order_id }
      };
    }

    void from_json(const json& j, CancelOrderResponse& t) {
      t.symbol = j.at("symbol").get<string>();
      t.order_id = j.at("orderId").get<long>();
      t.client_order_id = j.at("clientOrderId").get<string>();
      t.orig_client_order_id = j.at("origClientOrderId").get<string>();
    }
  }
}
