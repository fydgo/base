cmake_minimum_required(VERSION 2.8)

project(base)

add_definitions(-DUNICODE -D_UNICODE)
add_definitions(-DLIBCONFIG_STATIC -DYY_NO_UNISTD_H -DYY_USE_CONST)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/base/bin")

# Boost 1.66+ required.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
if(WIN32)
    find_package(Boost REQUIRED)
else()
    find_package(Boost REQUIRED COMPONENTS system filesystem date_time)
endif()
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    message(STATUS ${Boost_LIBRARIES})
endif()

# My understanding: for builder can find directory of header file.
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src/file)