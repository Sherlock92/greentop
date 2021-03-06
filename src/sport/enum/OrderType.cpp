/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/OrderType.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string OrderType::LIMIT = "LIMIT";
const std::string OrderType::LIMIT_ON_CLOSE = "LIMIT_ON_CLOSE";
const std::string OrderType::MARKET_ON_CLOSE = "MARKET_ON_CLOSE";

OrderType::OrderType() {
    valid = false;
}

OrderType::OrderType(const std::string& v) {
    if (v != LIMIT &&
        v != LIMIT_ON_CLOSE &&
        v != MARKET_ON_CLOSE) {
        throw std::invalid_argument("Invalid OrderType: " + v);
    }
    value = v;
    valid = true;
}

bool OrderType::operator<(const OrderType& other) const {
    return value < other.value;
}

bool OrderType::operator==(const OrderType& other) const {
    return value == other.value;
}

bool OrderType::operator!=(const OrderType& other) const {
    return value != other.value;
}

}
}
