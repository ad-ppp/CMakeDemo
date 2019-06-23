cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

set(export_dir ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../export)

add_library(
        jsoncpp
        SHARED

        src/json_tool.h
        src/json_reader.cpp
        src/json_valueiterator.inl
        src/json_value.cpp
        src/json_writer.cpp
        src/version.h.in
)

set_target_properties(
        jsoncpp
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${export_dir}/libsojsoncpp/lib/${ANDROID_ABI}")

add_custom_command(
        TARGET jsoncpp POST_BUILD
        # copy header files to export_dir
        COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/src/json" "${export_dir}/libsojsoncpp/include/json/"
)