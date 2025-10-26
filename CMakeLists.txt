cmake_minimum_required(VERSION 3.14)
project(CapstanDriveSAR)

add_executable(my_exec src/main.cpp "include/testFuncs.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Example syntax for adding package dependency i.e. OpenMP
#[[
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	target_link_libraries(my_exec PUBLIC OpenMP::OpenMP_CXX)
endif()
]] 

target_include_directories(my_exec
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
	)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	mytest
	tests/test.cpp
 "include/testFuncs.cpp")

target_include_directories(mytest
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
	)
target_link_libraries(
	mytest
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mytest)