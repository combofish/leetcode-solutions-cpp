cmake_minimum_required(VERSION 3.22)
project(Leetcode_Solution_Cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE DEBUG)
# SET(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-fsanitize=address -fno-omit-frame-pointer -Wall -Werror -Wreturn-type") # -Wextra

include_directories(src)

add_executable(Leetcode_Solution_Cpp
        src/combofish_utils.hpp
        src/factorial.cpp)

find_package(fmt)
target_link_libraries(Leetcode_Solution_Cpp fmt::fmt)

# ===== other ===== #
#add_executable(test_2 src/test_2.cpp)

# ===== HOT 100 ===== #
add_subdirectory(src/HOT-100)

# add_executable(hot_438_2 src/HOT-100/hot_438_2.cpp)
# find_package(fmt)
# target_link_libraries(hot_438_2 fmt::fmt)

#
# add_library(name SHARED )


# add_executable(off_42_2 src/Offer-2th/off_42_2.cpp src/Offer-2th/test.cpp )
# add_executable(off_42_2 src/Offer-2th/off_42_2.cpp )
# add_executable(off_42_2 src/Offer-2th/off_42_2.cpp)
#add_executable(hot_136 src/HOT-100-2/hot_136.cpp)
#add_executable(hot_136_ii src/HOT-100-2/hot_136_ii.cpp)
#add_executable(hot_121 src/HOT-100-2/hot_121.cpp)
#add_executable(hot_121_ii src/HOT-100-2/hot_121_ii.cpp)
#add_executable(solution_2 src/code-exam/test_01/solution_2.cpp)
#add_executable(solution_3 src/code-exam/test_01/solution_3_nouse.cpp)
add_executable(hot_141 src/HOT-100-2/hot_141.cpp)
add_executable(hot_49 src/HOT-100-2/hot_49.cpp)
add_executable(hot_49_ii src/HOT-100-2/hot_49_ii.cpp)
add_executable(hot_543 src/HOT-100-2/hot_543.cpp)
add_executable(hot_347 src/HOT-100-2/hot_347.cpp)