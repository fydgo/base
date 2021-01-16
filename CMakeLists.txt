cmake_minimum_required(VERSION 2.8)

project(base)

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

file(GLOB SRC CONFIGURE_DEPENDS 
        "*.cpp"
        "*.h"
)

add_library(base STATIC ${SRC})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/third_party/include)
