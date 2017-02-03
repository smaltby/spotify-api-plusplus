cmake_minimum_required(VERSION 3.5.1)
project(spotify-api-plusplus)
set (CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Build tests" ON)

set(SPOTIFY_PLUSPLUS_VERSION 1.0)
set(LIBS)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CURL_LIBRARIES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(src)

if(BUILD_TESTS)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/googletest/include)
    add_subdirectory(gtest)

    add_executable(TestGetAlbum tests/TestGetAlbum.cpp)

    target_link_libraries(
            TestGetAlbum
            gtest
            gtest_main
            spotify-api-plusplus
            pthread
    )

    enable_testing()
    add_test(TestGetAlbum ${PROJECT_BINARY_DIR}/TestGetAlbum)
endif(BUILD_TESTS)