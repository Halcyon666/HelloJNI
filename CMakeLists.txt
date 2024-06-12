cmake_minimum_required(VERSION 3.28)
project(HelloJNI C)

set(CMAKE_C_STANDARD 99)

# 检测操作系统类型
if(WIN32)
    set(JAVA_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
    set(JAVA_INCLUDE_PATH2 "$ENV{JAVA_HOME}/include/win32")
    set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
else()
    set(JAVA_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
    set(JAVA_INCLUDE_PATH2 "$ENV{JAVA_HOME}/include/linux")
    set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# 包含Java头文件
include_directories(${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2})

# 添加共享库
add_library(hello SHARED com_whalefall_learncases_callc_HelloJNI.c)

# 设置共享库输出名称和输出目录
set_target_properties(hello PROPERTIES
        OUTPUT_NAME "hello"
        LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY}
)

# 链接Java库
if (WIN32)
    target_link_libraries(hello)
else()
    target_link_libraries(hello dl)
endif()
