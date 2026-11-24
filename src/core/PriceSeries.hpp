#pragma once

#include <chrono>
#include <expected>
#include <vector>

namespace qrw{
    enum class PriceSeriesError{
        EmptyInput,
        SizeMismatch,
        UnsortedDate,
        NonPositivePrice
    };

    struct PriceSeries{
        std::vector<std::chrono::sys_days> dates;
        std::vector<double> closes;

        static auto create(std::vector<std::chrono::sys_days> dates, std::vector<double> closes) ->
            std::expected<PriceSeries, PriceSeriesError>; // std::expected<T,E> -> True or Error
    };
}