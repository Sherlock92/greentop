/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_TRANSFERRESPONSE_H
#define ACCOUNT_TRANSFERRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace account {
/**
 * Transfer operation response
 */
class TransferResponse : public JsonResponse {
    public:
        TransferResponse();

        TransferResponse(const std::string& transactionId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getTransactionId() const;
        void setTransactionId(const std::string& transactionId);


    private:
        /**
         * The id of the transfer transaction that will be used in tracking the transfers between
         * the wallets
         */
        std::string transactionId;
};

}
}

#endif // ACCOUNT_TRANSFERRESPONSE_H
