#include "PriceSeries.hpp"
#include "LogReturns.hpp"

#include <fmt/core.h>

#include <chrono>
#include <vector>

int main(){
    using namespace std::chrono;

    auto series = qrw::PriceSeries::create(
        {
            sys_days{year{2026}/1/1},
            sys_days{year{2026}/1/2},
            sys_days{year{2026}/1/3},
        },
        {
            100.0,
            110.0,
            105.0
        }
    );

    if(!series){
        fmt::print("Failed to create PriceSeries\n");
        return 1;
    }

    auto returns = qrw::log_returns(series->closes());

    if(!returns){
        fmt::print("Failed to compute returns\n");
        return 1;
    }

    fmt::print("Log returns:\n");

    for(double value : *returns){
        fmt::print("  {:.6f}\n", value);
    }

    return 0;
}