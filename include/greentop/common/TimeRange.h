/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef COMMON_TIMERANGE_H
#define COMMON_TIMERANGE_H

#include <ctime>
#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {
namespace common {
/**
 * TimeRange
 */
class TimeRange : public JsonMember {
    public:

        TimeRange(const std::tm& from = std::tm(),
            const std::tm& to = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::tm& getFrom() const;
        void setFrom(const std::tm& from);

        const std::tm& getTo() const;
        void setTo(const std::tm& to);


    private:
        /**
         * from, format: ISO 8601)
         */
        std::tm from;
        /**
         * to, format: ISO 8601
         */
        std::tm to;
};

}
}

#endif // COMMON_TIMERANGE_H
