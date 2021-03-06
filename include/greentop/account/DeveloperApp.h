/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_DEVELOPERAPP_H
#define ACCOUNT_DEVELOPERAPP_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/account/DeveloperAppVersion.h"

namespace greentop {
namespace account {
/**
 * Describes developer/vendor specific application
 */
class DeveloperApp : public JsonResponse {
    public:
        DeveloperApp();

        DeveloperApp(const std::string& appName,
            const Optional<int64_t>& appId,
            const std::vector<DeveloperAppVersion>& appVersions);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAppName() const;
        void setAppName(const std::string& appName);

        const Optional<int64_t>& getAppId() const;
        void setAppId(const Optional<int64_t>& appId);

        const std::vector<DeveloperAppVersion>& getAppVersions() const;
        void setAppVersions(const std::vector<DeveloperAppVersion>& appVersions);


    private:
        /**
         * The unique name of the application
         */
        std::string appName;
        /**
         * A unique id of this application
         */
        Optional<int64_t> appId;
        /**
         * The application versions (including application keys)
         */
        std::vector<DeveloperAppVersion> appVersions;
};

}
}

#endif // ACCOUNT_DEVELOPERAPP_H
