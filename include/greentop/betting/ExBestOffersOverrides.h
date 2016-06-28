/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXBESTOFFERSOVERRIDES_H
#define EXBESTOFFERSOVERRIDES_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/enum/RollupModel.h"

namespace greentop {

class ExBestOffersOverrides : public JsonMember {
    public:

        ExBestOffersOverrides(const int bestPricesDepth = -1,
            const RollupModel& rollupModel = RollupModel(),
            const int rollupLimit = -1,
            const Optional<double>& rollupLiabilityThreshold = Optional<double>(),
            const int rollupLiabiityFactor = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int getBestPricesDepth() const;
        void setBestPricesDepth(const int bestPricesDepth);

        const RollupModel& getRollupModel() const;
        void setRollupModel(const RollupModel& rollupModel);

        const int getRollupLimit() const;
        void setRollupLimit(const int rollupLimit);

        const Optional<double>& getRollupLiabilityThreshold() const;
        void setRollupLiabilityThreshold(const Optional<double>& rollupLiabilityThreshold);

        const int getRollupLiabiityFactor() const;
        void setRollupLiabiityFactor(const int rollupLiabiityFactor);


    private:
        int bestPricesDepth;
        RollupModel rollupModel;
        int rollupLimit;
        Optional<double> rollupLiabilityThreshold;
        int rollupLiabiityFactor;
};

}

#endif // EXBESTOFFERSOVERRIDES_H


