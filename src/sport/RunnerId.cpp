/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RunnerId.h"

namespace greentop {
namespace sport {

RunnerId::RunnerId() {
}

RunnerId::RunnerId(const std::string& marketId,
    const Optional<int64_t>& selectionId,
    const Optional<double>& handicap) :
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap) {
}

void RunnerId::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
}

Json::Value RunnerId::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    return json;
}

bool RunnerId::isValid() const {
    return marketId != "" && selectionId.isValid();
}

const std::string& RunnerId::getMarketId() const {
    return marketId;
}
void RunnerId::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const Optional<int64_t>& RunnerId::getSelectionId() const {
    return selectionId;
}
void RunnerId::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& RunnerId::getHandicap() const {
    return handicap;
}
void RunnerId::setHandicap(const Optional<double>& handicap) {
    this->handicap = handicap;
}


}
}
