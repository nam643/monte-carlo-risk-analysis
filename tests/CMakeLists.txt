find_package(Catch2 CONFIG REQUIRED)

add_executable(qrw_tests
    test_log_returns.cpp
)

target_link_libraries(
    qrw_tests
    PRIVATE
        qrw_analytics
        qrw_warnings
        Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(qrw_tests)