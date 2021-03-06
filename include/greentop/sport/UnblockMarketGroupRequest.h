/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_UNBLOCKMARKETGROUPREQUEST_H
#define SPORT_UNBLOCKMARKETGROUPREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketGroup.h"

namespace greentop {
namespace sport {

class UnblockMarketGroupRequest : public JsonRequest {
    public:
        UnblockMarketGroupRequest();

        UnblockMarketGroupRequest(const MarketGroup& marketGroup);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroup& getMarketGroup() const;
        void setMarketGroup(const MarketGroup& marketGroup);


    private:
        /**
         * Market group to unblock
         */
        MarketGroup marketGroup;
};

}
}

#endif // SPORT_UNBLOCKMARKETGROUPREQUEST_H
