#pragma once

#include <AnalyticsError.hpp>

#include <expected>
#include <span>
#include <vector>

namespace qrw{
    auto log_returns(std::span<const double> prices) -> std::expected<std::vector<double>, AnalyticsError>;
}