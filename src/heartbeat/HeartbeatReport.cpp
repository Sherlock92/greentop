/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/heartbeat/HeartbeatReport.h"

namespace greentop {

HeartbeatReport::HeartbeatReport() : actualTimeoutSeconds(-1) {
}

HeartbeatReport::HeartbeatReport(const ActionPerformed& actionPerformed,
    const int32_t actualTimeoutSeconds) :
    actionPerformed(actionPerformed),
    actualTimeoutSeconds(actualTimeoutSeconds) {
}

void HeartbeatReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("actionPerformed")) {
            actionPerformed = json["actionPerformed"].asString();
;
        }
        if (json.isMember("actualTimeoutSeconds")) {
            actualTimeoutSeconds = json["actualTimeoutSeconds"].asInt();
;
        }
    }
}

Json::Value HeartbeatReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (actionPerformed.isValid()) {
        json["actionPerformed"] = actionPerformed.getValue();
    }
    json["actualTimeoutSeconds"] = actualTimeoutSeconds;
    return json;
}

bool HeartbeatReport::isValid() const {
    return actionPerformed.isValid();
}

const ActionPerformed& HeartbeatReport::getActionPerformed() const {
    return actionPerformed;
}
void HeartbeatReport::setActionPerformed(const ActionPerformed& actionPerformed) {
    this->actionPerformed = actionPerformed;
}

const int32_t HeartbeatReport::getActualTimeoutSeconds() const {
    return actualTimeoutSeconds;
}
void HeartbeatReport::setActualTimeoutSeconds(const int32_t actualTimeoutSeconds) {
    this->actualTimeoutSeconds = actualTimeoutSeconds;
}


}



