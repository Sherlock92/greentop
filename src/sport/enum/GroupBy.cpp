/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/GroupBy.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string GroupBy::EVENT_TYPE = "EVENT_TYPE";
const std::string GroupBy::EVENT = "EVENT";
const std::string GroupBy::MARKET = "MARKET";
const std::string GroupBy::RUNNER = "RUNNER";
const std::string GroupBy::SIDE = "SIDE";
const std::string GroupBy::BET = "BET";

GroupBy::GroupBy() {
    valid = false;
};

GroupBy::GroupBy(const std::string& v) {

    if (v != EVENT_TYPE &&
        v != EVENT &&
        v != MARKET &&
        v != RUNNER &&
        v != SIDE &&
        v != BET) {
        throw std::invalid_argument("Invalid GroupBy: " + v);
    }

    value = v;
    valid = true;
}

bool GroupBy::operator<(const GroupBy& other) const {
    return value < other.value;
}

bool GroupBy::operator==(const GroupBy& other) const {
    return value == other.value;
}

bool GroupBy::operator!=(const GroupBy& other) const {
    return value != other.value;
}

}

