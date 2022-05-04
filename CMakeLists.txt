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

target_include_directories(UntitledDungeonCrawler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/lua/include
    ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sol2/include
    ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/tgui/include
    ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/include
    ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/json/include
    )

find_library(LUA_PATH lua)
find_library(TGUI_PATH tgui)
find_library(SDL_PATH SDL2)

target_link_libraries(UntitledDungeonCrawler PRIVATE ${LUA_PATH})
target_link_libraries(UntitledDungeonCrawler PRIVATE ${SDL_PATH})
target_link_libraries(UntitledDungeonCrawler PRIVATE ${TGUI_PATH})