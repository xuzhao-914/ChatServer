cmake_minimum_required (VERSION 3.0) #要求cmake最低的版本号
project (main) # 定义当前工程名字

#配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

#配置头文件搜索路径
#include_directories()
#配置库文件搜索路径
#link_directories()

#设置需要编译的源文件列表
set( SRC_LIST muduo_server.cpp)
#aux_source_directory(. SRC_LIST) # 定义变量，存储当前目录下的所有源文件

# 设置可执行文件的最终存储路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(server ${SRC_LIST}) #表示生成可执行文件server,由SRC_LIST里面的源文件编译而来
#表示server这个目标程序 需要连接 muduo_net muduo_base pthread 这三个库文件
target_link_libraries(server muduo_net muduo_base pthread)

#进入子目录下执行 CMakeLists.txt文件 这里的lib和tests里面都有可编译的代码文件
#add_subdirectory(lib)
#add_subdirectory(tests)

#set(CMAKE_BUILD_TYPE "Debug")#设置debug模式，如果没有这一行将不能调试设断点