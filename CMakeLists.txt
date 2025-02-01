cmake_minimum_required(VERSION 3.10)  # 确保使用 CMake 3.10 及以上
project(co_async_server)  # 项目名称

# 让 CMake 生成 compile_commands.json（自动支持 VS Code Clangd）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 强制使用 Clang 编译
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# 添加可执行文件
add_executable(server main.cpp)  # 生成 server 目标，可根据项目修改

# 指定 C++20 标准
target_compile_features(server PRIVATE cxx_std_20)

# 启用编译警告
target_compile_options(server PRIVATE -Wall -Wextra -Wpedantic)
