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

    class PriceSeries{
    public:
        static auto create(
            std::vector<std::chrono::sys_days> dates,
            std::vector<double> closes
        )
        -> std::expected<PriceSeries, PriceSeriesError>;

        [[nodiscard]]
        auto dates() const noexcept
            -> std::span<const std::chrono::sys_days>;

        [[nodiscard]]
        auto closes() const noexcept
            -> std::span<const double>;
        
        [[nodiscard]]
        auto size() const noexcept
            -> std::size_t;
    private:
        PriceSeries(
            std::vector<std::chrono::sys_days> dates,
            std::vector<double> closes
        );

        std::vector<std::chrono::sys_days> dates_;
        std::vector<double> closes_;
    };
}