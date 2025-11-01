if (MSVC)
    add_compile_options(/FS)
endif()

add_library(
    tests
    tests.h
    tests.cpp
    )

target_include_directories(tests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")