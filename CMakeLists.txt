cmake_minimum_required(VERSION 3.22)
project(Leetcode_Solution_Cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "DEBUG")

# SET(CMAKE_BUILD_TYPE Release)

include_directories("/usr/local/include")

set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer \
                    -fno-optimize-sibling-calls -Wall -Werror -Wreturn-type")
# -Wextra -fsanitize=memory -fsanitize=thread

include_directories(src)

# add_executable(Leetcode_Solution_Cpp
#         src/combofish_utils.hpp
#         src/factorial.cpp)

# find_package(fmt)
# target_link_libraries(Leetcode_Solution_Cpp fmt::fmt)

# add_library(name SHARED )

# ===== HOT 100 ===== #
# add_subdirectory(src/HOT-100)

# add_executable(hot_438_2 src/HOT-100/hot_438_2.cpp)
# find_package(fmt)
# target_link_libraries(hot_438_2 fmt::fmt)


#include_directories(/usr/include/mysql)
#add_executable(mysql_test src/h1f2/mysql_test.cpp)
#target_link_libraries(mysql_test mysqlclient)
# g++ -o test test.c `mysql_config --cflags --libs`

# ===== other ===== #


#add_executable(sol_71 src/h1f2/sol_71.cpp)
#add_executable(sol_1472 src/h1f2/sol_1472.cpp)
#add_executable(sol_703 src/h1f2/sol_703.cpp)
#add_executable(sol_662 src/h1f2/sol_662.cpp)
#add_executable(sol_69 src/h1f2/sol_69.cpp)
add_executable(test_01 src/code-exam-2/test-01/test_01.cpp)
add_executable(test_02 src/code-exam-2/test-01/test_02.cpp)
add_executable(test_02_2 src/code-exam-2/test-01/test_02_2.cpp)
add_executable(test_03 src/code-exam-2/test-01/test_03.cpp)
add_executable(sol_38 src/h1f2/sol_38.cpp)