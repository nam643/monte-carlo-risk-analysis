add_library(qrw_core)

target_sources(
    qrw_core
    PRIVATE
        PriceSeries.cpp
)

target_include_directories(
    qrw_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
    qrw_core
    PRIVATE
        qrw_warnings
)