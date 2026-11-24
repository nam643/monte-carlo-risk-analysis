#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "LogReturns.hpp"

#include <cmath>
#include <vector>

TEST_CASE("known log return"){
    const std::vector<double> prices{
        100.0,
        110.0
    };

    const auto result = qrw::log_returns(prices);

    REQUIRE(result.has_value());

    REQUIRE(result->front() == Catch::Approx(std::log(1.1)));
}

TEST_CASE("empty input returns error"){
    const std::vector<double> prices{};

    const auto result = qrw::log_returns(prices);

    REQUIRE_FALSE(result.has_value());

    REQUIRE(result.error() == qrw::AnalyticsError::InsufficientData);
}

TEST_CASE("zero price returns error"){
    const std::vector<double> prices{
        100.0,
        0.0
    };

    const auto result = qrw::log_returns(prices);

    REQUIRE_FALSE(result.has_value());

    REQUIRE(result.error() == qrw::AnalyticsError::NonPositivePrice);
}