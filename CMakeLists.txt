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


add_executable(off_42_2 src/Offer-2th/off_42_2.cpp src/Offer-2th/test.cpp )
# add_executable(off_42_2 src/Offer-2th/off_42_2.cpp )
# add_executable(off_42_2 src/Offer-2th/off_42_2.cpp)