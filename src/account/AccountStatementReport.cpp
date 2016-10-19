/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountStatementReport.h"

namespace greentop {

AccountStatementReport::AccountStatementReport() : moreAvailable(false) {
}

AccountStatementReport::AccountStatementReport(const std::vector<StatementItem>& accountStatement,
    const bool moreAvailable) :
    accountStatement(accountStatement),
    moreAvailable(moreAvailable) {
}

void AccountStatementReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("accountStatement")) {
            for (unsigned i = 0; i < json["accountStatement"].size(); ++i) {
            StatementItem statementItem;
            statementItem.fromJson(json["accountStatement"][i]);
            accountStatement.push_back(statementItem);
        }
;
        }
        if (json.isMember("moreAvailable")) {
            moreAvailable = json["moreAvailable"].asBool();
;
        }
    }
}

Json::Value AccountStatementReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (accountStatement.size() > 0) {
        for (unsigned i = 0; i < accountStatement.size(); ++i) {
            json["accountStatement"].append(accountStatement[i].toJson());
        }
    }
    json["moreAvailable"] = moreAvailable;
    return json;
}

bool AccountStatementReport::isValid() const {
    return accountStatement.size() > 0;
}

const std::vector<StatementItem>& AccountStatementReport::getAccountStatement() const {
    return accountStatement;
}
void AccountStatementReport::setAccountStatement(const std::vector<StatementItem>& accountStatement) {
    this->accountStatement = accountStatement;
}

const bool AccountStatementReport::getMoreAvailable() const {
    return moreAvailable;
}
void AccountStatementReport::setMoreAvailable(const bool moreAvailable) {
    this->moreAvailable = moreAvailable;
}


}



