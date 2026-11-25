#include "PriceSeries.hpp"
#include <algorithm>

namespace qrw{
    PriceSeries::PriceSeries(
        std::vector<std::chrono::sys_days> dates,
        std::vector<double> closes)
        : dates_(std::move(dates))
        , closes_(std::move(closes)){}
    
    auto PriceSeries::create(
        std::vector<std::chrono::sys_days> dates,
        std::vector<double> closes
    )
    -> std::expected<PriceSeries, PriceSeriesError>{
        if(dates.empty() || closes.empty()){
            return std::unexpected(PriceSeriesError::EmptyInput);
        }

        if(dates.size() != closes.size()){
            return std::unexpected(PriceSeriesError::SizeMismatch);
        }

        if(!std::ranges::is_sorted(dates)){
            return std::unexpected(PriceSeriesError::UnsortedDate);
        }

        if(std::ranges::any_of(
            closes,
            [](double value){
                return value <= 0.0;
            }
        )){
            return std::unexpected(PriceSeriesError::NonPositivePrice);
        }

        return PriceSeries{
            std::move(dates),
            std::move(closes)
        };
    }

    auto PriceSeries::dates() const noexcept 
        -> std::span<const std::chrono::sys_days>{
        return dates_;
    }

    auto PriceSeries::closes() const noexcept
        -> std::span<const double>
    {
        return closes_;
    }

    auto PriceSeries::size() const noexcept
        -> std::size_t
    {
        return closes_.size();
    }
}