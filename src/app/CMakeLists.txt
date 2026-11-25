add_executable(qrw_app
    main.cpp
)

target_link_libraries(
    qrw_app
    PRIVATE
        qrw_core
        qrw_analytics
        qrw_warnings
        fmt::fmt
)