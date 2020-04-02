/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/OrderBy.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string OrderBy::BY_BET = "BY_BET";
const std::string OrderBy::BY_MARKET = "BY_MARKET";
const std::string OrderBy::BY_PLACE_TIME = "BY_PLACE_TIME";
const std::string OrderBy::BY_MATCH_TIME = "BY_MATCH_TIME";
const std::string OrderBy::BY_VOID_TIME = "BY_VOID_TIME";
const std::string OrderBy::BY_SETTLED_TIME = "BY_SETTLED_TIME";

OrderBy::OrderBy() {
    valid = false;
}

OrderBy::OrderBy(const std::string& v) {
    if (v != BY_BET &&
        v != BY_MARKET &&
        v != BY_PLACE_TIME &&
        v != BY_MATCH_TIME &&
        v != BY_VOID_TIME &&
        v != BY_SETTLED_TIME) {
        throw std::invalid_argument("Invalid OrderBy: " + v);
    }
    value = v;
    valid = true;
}

bool OrderBy::operator<(const OrderBy& other) const {
    return value < other.value;
}

bool OrderBy::operator==(const OrderBy& other) const {
    return value == other.value;
}

bool OrderBy::operator!=(const OrderBy& other) const {
    return value != other.value;
}

}
}
