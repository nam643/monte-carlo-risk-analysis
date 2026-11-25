#include "LogReturns.hpp"

#include <cmath>

namespace qrw{
    auto log_returns(std::span<const double> prices) -> std::expected<std::vector<double>, AnalyticsError>{
        if(prices.size() < 2){
            return std::unexpected(AnalyticsError::InsufficientData);
        }

        for(double p : prices){
            if(!std::isfinite(p) || p<=0.0){
                return std::unexpected(AnalyticsError::NonPositivePrice);
            }
        }

        std::vector<double> out;
        out.reserve(prices.size()-1);

        for(auto i{1uz}; i<prices.size(); i++){
            out.push_back(std::log(prices[i]/prices[i-1]));
        }

        return out;
    }
}