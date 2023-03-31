cmake_minimum_required(VERSION 3.22)
project(Leetcode_Solution_Cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE DEBUG)
# SET(CMAKE_BUILD_TYPE Release)

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


# ===== other ===== #

add_executable(test_01 src/code-exam/test_09/test_01.cpp)
add_executable(test_02 src/code-exam/test_09/test_02.cpp)