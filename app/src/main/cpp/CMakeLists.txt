cmake_minimum_required(VERSION 3.4.1)

# 设置变量 找到存放资源的目录，".."代表上一级目录
set(export_dir ${CMAKE_SOURCE_DIR}/../../../../export)

# 添加.a静态库(hello)
add_library(lib_a_hello STATIC IMPORTED)
# 链接. Targets can have properties that affect how they are built.
set_target_properties(
        lib_a_hello
        PROPERTIES IMPORTED_LOCATION ${export_dir}/libahello/lib/${ANDROID_ABI}/libhello.a)

# 添加.so动态库(hello)
add_library(lib_so_hello STATIC IMPORTED)
# 链接. Targets can have properties that affect how they are built.
set_target_properties(
        lib_so_hello
        PROPERTIES IMPORTED_LOCATION ${export_dir}/libsohello/lib/${ANDROID_ABI}/libhello.so)

# 添加.so动态库(jsoncpp)
add_library(lib_so_jsoncpp SHARED IMPORTED)
# 链接. Targets can have properties that affect how they are built.
set_target_properties(
        lib_so_jsoncpp
        PROPERTIES IMPORTED_LOCATION ${export_dir}/libsojsoncpp/lib/${ANDROID_ABI}/libjsoncpp.so)

# 将需要打包的资源添加进来
add_library(
        # 库名字
        native_test
        # 库类型
        SHARED

        # 包含的cpp
        native_hello.cpp
        native_so_jsoncpp_test.cpp
        native_a_hello_test.cpp
        native_so_hello_test.cpp
)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# 链接头文件
target_include_directories(
        native_test
        PRIVATE

        # native_a_hello_test 需要的头文件
        ${export_dir}/libahello/include
        # native_so_hello_test 需要的头文件
        ${export_dir}/libsohello/include
        # native_so_jsoncpp_test 需要的头文件
        ${export_dir}/libsojsoncpp/include
)

# 链接库
target_link_libraries(
        native_test
        android
        log
        # 链接 hello.a
        lib_a_hello
        # 链接 hello.so
        lib_so_hello
        # 链接 jsoncpp.so
        lib_so_jsoncpp
)