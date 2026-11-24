add_library(qrw_analytics)

target_sources(
    qrw_analytics
    PRIVATE
        LogReturns.cpp
)

target_include_directories(
    qrw_analytics
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
    qrw_analytics
    PUBLIC
        qrw_core
    PRIVATE
        qrw_warnings
)