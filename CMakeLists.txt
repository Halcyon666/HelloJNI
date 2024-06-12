cmake_minimum_required(VERSION 3.28)
project(HelloJNI C)

set(CMAKE_C_STANDARD 99)

# 包含Java头文件
include_directories("$ENV{JAVA_HOME}/include" "$ENV{JAVA_HOME}/include/win32")

# 添加共享库
add_library(hello SHARED com_whalefall_learncases_callc_HelloJNI.c)

# 设置共享库输出名称
set_target_properties(hello PROPERTIES OUTPUT_NAME "hello")

# 链接Java库
if (WIN32)
    target_link_libraries(hello "${CMAKE_JAVA_LIBRARY}")
else()
    target_link_libraries(hello "${CMAKE_JAVA_LIBRARY}" dl)
endif()
