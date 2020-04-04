/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTVENUESRESPONSE_H
#define SPORT_LISTVENUESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/VenueResult.h"

namespace greentop {
namespace sport {

class ListVenuesResponse : public JsonResponse {
    public:
        ListVenuesResponse();

        ListVenuesResponse(const std::vector<VenueResult>& venueResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<VenueResult>& getVenueResults() const;
        void setVenueResults(const std::vector<VenueResult>& venueResults);


    private:

        std::vector<VenueResult> venueResults;
};

}
}

#endif // SPORT_LISTVENUESRESPONSE_H
