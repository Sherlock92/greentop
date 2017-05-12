/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RunnerCatalog.h"

namespace greentop {

RunnerCatalog::RunnerCatalog() : selectionId(-1) {
}

RunnerCatalog::RunnerCatalog(const int64_t selectionId,
    const std::string& runnerName,
    const double handicap,
    const int32_t sortPriority,
    const std::map<std::string, std::string> metadata) :
    selectionId(selectionId),
    runnerName(runnerName),
    handicap(handicap),
    sortPriority(sortPriority),
    metadata(metadata) {
}

void RunnerCatalog::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("runnerName")) {
        runnerName = json["runnerName"].asString();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
    if (json.isMember("sortPriority")) {
        sortPriority = json["sortPriority"].asInt();
    }
    if (json.isMember("metadata")) {
        for (Json::ValueConstIterator itr = json["metadata"].begin(); itr != json["metadata"].end(); ++itr) {
            std::string value;
            value = (*itr).asString();
            metadata[itr.key().asString()] = value;
        }
    }
}

Json::Value RunnerCatalog::toJson() const {
    Json::Value json(Json::objectValue);
    json["selectionId"] = selectionId;
    if (runnerName != "") {
        json["runnerName"] = runnerName;
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    if (sortPriority.isValid()) {
        json["sortPriority"] = sortPriority.toJson();
    }
    if (metadata.size() > 0) {
        json["metadata"] = Json::objectValue;
        for (std::map<std::string, std::string>::const_iterator it = metadata.begin(); it != metadata.end(); ++it) {
            json["metadata"][it->first] = it->second;
        }
    }
    return json;
}

bool RunnerCatalog::isValid() const {
    return runnerName != "" && handicap.isValid() && sortPriority.isValid();
}

const int64_t RunnerCatalog::getSelectionId() const {
    return selectionId;
}
void RunnerCatalog::setSelectionId(const int64_t selectionId) {
    this->selectionId = selectionId;
}

const std::string& RunnerCatalog::getRunnerName() const {
    return runnerName;
}
void RunnerCatalog::setRunnerName(const std::string& runnerName) {
    this->runnerName = runnerName;
}

const double RunnerCatalog::getHandicap() const {
    return handicap;
}
void RunnerCatalog::setHandicap(const double handicap) {
    this->handicap = handicap;
}

const int32_t RunnerCatalog::getSortPriority() const {
    return sortPriority;
}
void RunnerCatalog::setSortPriority(const int32_t sortPriority) {
    this->sortPriority = sortPriority;
}

const std::map<std::string, std::string>& RunnerCatalog::getMetadata() const {
    return metadata;
}
void RunnerCatalog::setMetadata(const std::map<std::string, std::string>& metadata) {
    this->metadata = metadata;
}


}



