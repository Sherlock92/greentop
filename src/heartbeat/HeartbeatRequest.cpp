/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/heartbeat/HeartbeatRequest.h"

namespace greentop {
namespace heartbeat {

HeartbeatRequest::HeartbeatRequest() {
}

HeartbeatRequest::HeartbeatRequest(const Optional<int32_t>& preferredTimeoutSeconds) :
    preferredTimeoutSeconds(preferredTimeoutSeconds) {
}

void HeartbeatRequest::fromJson(const Json::Value& json) {
    if (json.isMember("preferredTimeoutSeconds")) {
        preferredTimeoutSeconds = json["preferredTimeoutSeconds"].asInt();
    }
}

Json::Value HeartbeatRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (preferredTimeoutSeconds.isValid()) {
        json["preferredTimeoutSeconds"] = preferredTimeoutSeconds.toJson();
    }
    return json;
}

bool HeartbeatRequest::isValid() const {
    return preferredTimeoutSeconds.isValid();
}

const Optional<int32_t>& HeartbeatRequest::getPreferredTimeoutSeconds() const {
    return preferredTimeoutSeconds;
}
void HeartbeatRequest::setPreferredTimeoutSeconds(const Optional<int32_t>& preferredTimeoutSeconds) {
    this->preferredTimeoutSeconds = preferredTimeoutSeconds;
}


}
}
