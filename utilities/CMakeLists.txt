if (MSVC)
    add_compile_options(/FS)
endif()

add_library(
    utilities
    types.h
    )

set_target_properties(utilities PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")