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

if (WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(LUA_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/lua/win32/liblua.lib)
        set(TGUI_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/tgui/win32/libtgui-s.lib)
        set(SDL_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/win32/libSDL2.lib)
        set(SDLMAIN_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/win32/libSDL2main.lib)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(LUA_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/lua/win64/liblua.lib)
        set(TGUI_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/tgui/win64/libtgui-s.lib)
        set(SDL_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/win64/libSDL2.lib)
        set(SDLMAIN_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/win64/libSDL2main.lib)
    endif()
elseif (UNIX)
    set(LUA_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/lua/unix/liblua.a)
    set(TGUI_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/tgui/unix/libtgui-s.a)
    set(SDL_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/unix/libSDL2.a)
    set(SDLMAIN_PATH ${CMAKE_CURRENT_SOURCE_DIRECTORY}/lib/sdl/unix/libSDL2main.a)
endif()

add_library(Lua STATIC IMPORTED)
add_library(TGUI STATIC IMPORTED)
add_library(SDL STATIC IMPORTED)
add_library(SDLmain STATIC IMPORTED)

set_target_properties(Lua PROPERTIES IMPORTED_LOCATION ${LUA_PATH})
set_target_properties(TGUI PROPERTIES IMPORTED_LOCATION ${TGUI_PATH})
set_target_properties(SDL PROPERTIES IMPORTED_LOCATION ${SDL_PATH})
set_target_properties(SDLmain PROPERTIES IMPORTED_LOCATION ${SDLMAIN_PATH})