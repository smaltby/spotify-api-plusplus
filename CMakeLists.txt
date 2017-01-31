cmake_minimum_required(VERSION 3.5.1)

project(spotify-plusplus)

set (CMAKE_CXX_STANDARD 11)

set(SPOTIFY_PLUSPLUS_VERSION 1.0)

set(LIBS)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CURL_LIBRARIES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(spotify)
