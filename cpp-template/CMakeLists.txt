cmake_minimum_required(VERSION 3.16)
project(cpp_template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 收集公共代码（leetcode/editor/common 目录）
file(GLOB_RECURSE COMMON_SOURCES "leetcode/editor/common/*.cpp")

# 编译公共代码为库（如果存在）
if(COMMON_SOURCES)
    add_library(common STATIC ${COMMON_SOURCES})
endif()

# 收集根目录的题目文件（68道题目）
file(GLOB ROOT_SOURCES "*.cpp")

# 收集 leetcode/editor 目录下的文件
file(GLOB_RECURSE EDITOR_SOURCES "leetcode/editor/cn/*.cpp" "leetcode/editor/en/*.cpp")

# 合并所有源文件
set(ALL_SOURCES ${ROOT_SOURCES} ${EDITOR_SOURCES})

# 计数器用于生成唯一目标名
set(target_counter 0)

# 为每个包含 main 函数的文件生成可执行文件
foreach(source_file ${ALL_SOURCES})
    # 读取文件内容检查是否包含 main 函数
    file(READ ${source_file} file_content)
    string(FIND "${file_content}" "int main(" main_pos)
    string(FIND "${file_content}" "int main (" main_pos2)
    
    # 如果文件包含 main 函数
    if(NOT main_pos EQUAL -1 OR NOT main_pos2 EQUAL -1)
        # 获取文件名
        get_filename_component(filename ${source_file} NAME_WE)
        get_filename_component(dir ${source_file} DIRECTORY)
        
        # 生成有效的目标名称（使用计数器和哈希值）
        string(MD5 name_hash "${source_file}")
        string(SUBSTRING "${name_hash}" 0 8 hash_short)
        
        # 根据目录生成前缀
        if(dir STREQUAL CMAKE_SOURCE_DIR)
            # 根目录文件，使用 lc_ 前缀加哈希值
            set(target_name "lc_${hash_short}")
        else()
            # 子目录文件，使用目录路径作为前缀
            file(RELATIVE_PATH relative_dir ${CMAKE_SOURCE_DIR}/leetcode ${dir})
            string(REPLACE "/" "_" unique_prefix "${relative_dir}")
            set(target_name "${unique_prefix}_${hash_short}")
        endif()
        
        # 生成可执行文件
        add_executable(${target_name} ${source_file})
        
        # 设置 include 目录，确保能找到 ../common/ 目录
        target_include_directories(${target_name} PRIVATE ${CMAKE_SOURCE_DIR}/..)
        
        # 如果存在 common 库，链接它
        if(TARGET common)
            target_link_libraries(${target_name} common)
        endif()
        
        # 增加计数器
        math(EXPR target_counter "${target_counter} + 1")
    endif()
endforeach()

message(STATUS "Configured ${target_counter} executable targets")

# 导出 compile_commands.json 用于 LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
