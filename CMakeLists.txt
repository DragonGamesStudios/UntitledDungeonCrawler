cmake_minimum_required(VERSION 3.19)

project(UntitledDungeonCrawler VERSION 0.0)

set(UDC_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(UDC_SOURCE_CPP
    ${UDC_SOURCE_PATH}/main.cpp
)

set(UDC_SOURCE_HPP
)

source_group(Sources ${UDC_SOURCE_CPP})
source_group(Headers ${UDC_SOURCE_HPP})

add_executable(UntitledDungeonCrawler ${UDC_SOURCE_CPP} ${UDC_SOURCE_HPP})