#include "PriceSeries.hpp"
#include <algorithm>

namespace qrw{
    auto PriceSeries::create(std::vector<std::chrono::sys_days> dates, std::vector<double> closes)
        -> std::expected<PriceSeries, PriceSeriesError>
    {
        if(dates.empty() || closes.empty()){
            return std::unexpected(PriceSeriesError::EmptyInput);
        }

        if(dates.size() != closes.size()){
            return std::unexpected(PriceSeriesError::SizeMismatch);
        }

        if(!std::ranges::is_sorted(dates)){
            return std::unexpected(PriceSeriesError::UnsortedDate);
        }

        if(std::ranges::any_of(closes, [](double p){return p <= 0.0;})){
            return std::unexpected(PriceSeriesError::NonPositivePrice);
        }

        return PriceSeries{
            .dates = std::move(dates),
            .closes = std::move(closes)
        };
    }
}