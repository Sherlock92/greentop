/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/InstructionReportErrorCode.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string InstructionReportErrorCode::INVALID_BET_SIZE = "INVALID_BET_SIZE";
const std::string InstructionReportErrorCode::INVALID_RUNNER = "INVALID_RUNNER";
const std::string InstructionReportErrorCode::BET_TAKEN_OR_LAPSED = "BET_TAKEN_OR_LAPSED";
const std::string InstructionReportErrorCode::BET_IN_PROGRESS = "BET_IN_PROGRESS";
const std::string InstructionReportErrorCode::RUNNER_REMOVED = "RUNNER_REMOVED";
const std::string InstructionReportErrorCode::MARKET_NOT_OPEN_FOR_BETTING = "MARKET_NOT_OPEN_FOR_BETTING";
const std::string InstructionReportErrorCode::LOSS_LIMIT_EXCEEDED = "LOSS_LIMIT_EXCEEDED";
const std::string InstructionReportErrorCode::MARKET_NOT_OPEN_FOR_BSP_BETTING = "MARKET_NOT_OPEN_FOR_BSP_BETTING";
const std::string InstructionReportErrorCode::INVALID_PRICE_EDIT = "INVALID_PRICE_EDIT";
const std::string InstructionReportErrorCode::INVALID_ODDS = "INVALID_ODDS";
const std::string InstructionReportErrorCode::INSUFFICIENT_FUNDS = "INSUFFICIENT_FUNDS";
const std::string InstructionReportErrorCode::INVALID_PERSISTENCE_TYPE = "INVALID_PERSISTENCE_TYPE";
const std::string InstructionReportErrorCode::ERROR_IN_MATCHER = "ERROR_IN_MATCHER";
const std::string InstructionReportErrorCode::INVALID_BACK_LAY_COMBINATION = "INVALID_BACK_LAY_COMBINATION";
const std::string InstructionReportErrorCode::ERROR_IN_ORDER = "ERROR_IN_ORDER";
const std::string InstructionReportErrorCode::INVALID_BID_TYPE = "INVALID_BID_TYPE";
const std::string InstructionReportErrorCode::INVALID_BET_ID = "INVALID_BET_ID";
const std::string InstructionReportErrorCode::CANCELLED_NOT_PLACED = "CANCELLED_NOT_PLACED";
const std::string InstructionReportErrorCode::RELATED_ACTION_FAILED = "RELATED_ACTION_FAILED";
const std::string InstructionReportErrorCode::NO_ACTION_REQUIRED = "NO_ACTION_REQUIRED";

InstructionReportErrorCode::InstructionReportErrorCode() {
    valid = false;
};

InstructionReportErrorCode::InstructionReportErrorCode(const std::string& v) {

    if (v != INVALID_BET_SIZE &&
        v != INVALID_RUNNER &&
        v != BET_TAKEN_OR_LAPSED &&
        v != BET_IN_PROGRESS &&
        v != RUNNER_REMOVED &&
        v != MARKET_NOT_OPEN_FOR_BETTING &&
        v != LOSS_LIMIT_EXCEEDED &&
        v != MARKET_NOT_OPEN_FOR_BSP_BETTING &&
        v != INVALID_PRICE_EDIT &&
        v != INVALID_ODDS &&
        v != INSUFFICIENT_FUNDS &&
        v != INVALID_PERSISTENCE_TYPE &&
        v != ERROR_IN_MATCHER &&
        v != INVALID_BACK_LAY_COMBINATION &&
        v != ERROR_IN_ORDER &&
        v != INVALID_BID_TYPE &&
        v != INVALID_BET_ID &&
        v != CANCELLED_NOT_PLACED &&
        v != RELATED_ACTION_FAILED &&
        v != NO_ACTION_REQUIRED) {
        throw std::invalid_argument("Invalid InstructionReportErrorCode: " + v);
    }

    value = v;
    valid = true;
}

bool InstructionReportErrorCode::operator<(const InstructionReportErrorCode& other) const {
    return value < other.value;
}

bool InstructionReportErrorCode::operator==(const InstructionReportErrorCode& other) const {
    return value == other.value;
}

bool InstructionReportErrorCode::operator!=(const InstructionReportErrorCode& other) const {
    return value != other.value;
}

}
