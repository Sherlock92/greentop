/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/Side.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string Side::BACK = "BACK";
const std::string Side::LAY = "LAY";

Side::Side() {
    valid = false;
}

Side::Side(const std::string& v) {
    if (v != BACK &&
        v != LAY) {
        throw std::invalid_argument("Invalid Side: " + v);
    }
    value = v;
    valid = true;
}

bool Side::operator<(const Side& other) const {
    return value < other.value;
}

bool Side::operator==(const Side& other) const {
    return value == other.value;
}

bool Side::operator!=(const Side& other) const {
    return value != other.value;
}

}
