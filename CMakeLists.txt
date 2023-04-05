cmake_minimum_required(VERSION 3.22)
project(Leetcode_Solution_Cpp)

set(CMAKE_CXX_STANDARD 11)
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

add_executable(hot_297_serialize-and-deserialize-binary-tree src/HOT-100-2/hot_297_serialize-and-deserialize-binary-tree.cpp)
add_executable(hot_72_edit-distance src/HOT-100-2/hot_72_edit-distance.cpp)
add_executable(hot_399_evaluate-division src/HOT-100-2/hot_399_evaluate-division.cpp)
add_executable(hot_399_evaluate-division_ii src/HOT-100-2/hot_399_evaluate-division_ii.cpp)
add_executable(hot_253_meeting-rooms-ii src/HOT-100-2/hot_253_meeting-rooms-ii.cpp)
add_executable(hot_309_best-time-to-buy-and-sell-stock-with-cooldown src/HOT-100-2/hot_309_best-time-to-buy-and-sell-stock-with-cooldown.cpp)
add_executable(hot_10_regular-expression-matching src/HOT-100-2/hot_10_regular-expression-matching.cpp)