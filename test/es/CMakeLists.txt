cmake_minimum_required(VERSION 3.0)

# 将src目录下的源文件放到变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/code/${MODULE}/src SOURCE_PATH)

# 设置头文件搜索路径
include_directories(
					${PROJECT_SOURCE_DIR}/gtest/include/
                    ${PROJECT_SOURCE_DIR}/code/${MODULE}/inc
					)
					
# 添加额外的编译选项
add_compile_options(-I ${PROJECT_SOURCE_DIR})

# 生成target文件
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_PATH} demo.c)

# 链接gtest库文件
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC gtest pthread)
