find_package(Catch2 CONFIG REQUIRED)

add_executable(qrw_tests
    test_log_returns.cpp
)

target_link_libraries(
    qrw_tests
    PRIVATE
        Catch2::Catch2WithMain
        qrw_analytics
        qrw_warnings
)