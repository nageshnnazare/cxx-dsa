cmake_minimum_required(VERSION 3.13) 
project(cxx_dsa)             
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")   

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(
#   hello_test
#   Test/arrays/hello.cc
# )
# target_link_libraries(
#   hello_test
#   gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)

add_subdirectory(${CMAKE_SOURCE_DIR}/arrays)
add_subdirectory(${CMAKE_SOURCE_DIR}/binarySearch)
add_subdirectory(${CMAKE_SOURCE_DIR}/designPatterns)
add_subdirectory(${CMAKE_SOURCE_DIR}/greedyAlgorithms)
add_subdirectory(${CMAKE_SOURCE_DIR}/heaps)
add_subdirectory(${CMAKE_SOURCE_DIR}/linkedList)
add_subdirectory(${CMAKE_SOURCE_DIR}/recursion)
add_subdirectory(${CMAKE_SOURCE_DIR}/sorting)
add_subdirectory(${CMAKE_SOURCE_DIR}/slidingWindow)
add_subdirectory(${CMAKE_SOURCE_DIR}/stacks)
add_subdirectory(${CMAKE_SOURCE_DIR}/dynamicProgramming)
add_subdirectory(${CMAKE_SOURCE_DIR}/graphs)
add_subdirectory(${CMAKE_SOURCE_DIR}/strings)