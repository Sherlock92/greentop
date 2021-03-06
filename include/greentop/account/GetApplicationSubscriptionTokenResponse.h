/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H
#define ACCOUNT_GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace account {

class GetApplicationSubscriptionTokenResponse : public JsonResponse {
    public:
        GetApplicationSubscriptionTokenResponse();

        GetApplicationSubscriptionTokenResponse(const std::string& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getResponse() const;
        void setResponse(const std::string& response);


    private:

        std::string response;
};

}
}

#endif // ACCOUNT_GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H
