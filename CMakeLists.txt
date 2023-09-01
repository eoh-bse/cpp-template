cmake_minimum_required(VERSION 3.26)

if(NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(cpp_template
	VERSION 0.1.0
	DESCRIPTION "C++ Template"
	LANGUAGES CXX)

set(DEBUG_FLAGS "-g -Wall -Wpedantic -Wextra -Wconversion -pthread -fsanitize=address,undefined")
set(RELEASE_FLAGS "-O2 -pthread")

message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
	message("Using flags: ${DEBUG_FLAGS}")
	set(CMAKE_CXX_FLAGS ${DEBUG_FLAGS})
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
	message("Using flags: ${RELEASE_FLAGS}")
	set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
else()
	message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")

include(FetchContent)

set(ABSL_PROPAGATE_CXX_STD ON)
FetchContent_Declare(
    abseil
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG 20230802.0
)
FetchContent_MakeAvailable(abseil)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB MAIN "${PROJECT_SOURCE_DIR}/src/main.cpp")
file(GLOB ENTITIES "${PROJECT_SOURCE_DIR}/src/entities/*.cpp")
add_executable(${PROJECT_NAME} ${MAIN} ${SOURCES} ${ENTITIES})
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(${PROJECT_NAME} PRIVATE absl::strings absl::flat_hash_map)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

enable_testing()
set(TESTS all_tests)
file(GLOB TEST_MAIN "${PROJECT_SOURCE_DIR}/tests/main.cpp")
file(GLOB ENTITIES_TEST "${PROJECT_SOURCE_DIR}/tests/entities/*.cpp")
add_executable(${TESTS} ${TEST_MAIN} ${ENTITIES_TEST} ${ENTITIES})
target_include_directories(${TESTS} PRIVATE "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(${TESTS} PRIVATE GTest::gtest_main absl::strings absl::flat_hash_map)

include(GoogleTest)
gtest_discover_tests(all_tests)
