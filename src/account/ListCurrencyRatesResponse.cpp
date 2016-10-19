/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ListCurrencyRatesResponse.h"

namespace greentop {

ListCurrencyRatesResponse::ListCurrencyRatesResponse() {
}

ListCurrencyRatesResponse::ListCurrencyRatesResponse(const std::vector<CurrencyRate>& currencyRates) :
    currencyRates(currencyRates) {
}

void ListCurrencyRatesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            CurrencyRate currencyRate;
            currencyRate.fromJson(json[i]);
            currencyRates.push_back(currencyRate);
        }
    }
}

Json::Value ListCurrencyRatesResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (currencyRates.size() > 0) {
        for (unsigned i = 0; i < currencyRates.size(); ++i) {
            json.append(currencyRates[i].toJson());
        }
    }
    return json;
}

bool ListCurrencyRatesResponse::isValid() const {
    return currencyRates.size() > 0;
}

const std::vector<CurrencyRate>& ListCurrencyRatesResponse::getCurrencyRates() const {
    return currencyRates;
}
void ListCurrencyRatesResponse::setCurrencyRates(const std::vector<CurrencyRate>& currencyRates) {
    this->currencyRates = currencyRates;
}


}



