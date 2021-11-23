cmake_minimum_required(VERSION 3.15)

# PROJEKTNAME mit Ihrem Belegnamen ersetzen
project(PROJEKTNAME VERSION 1.0 LANGUAGES CXX)

## C++17 wird benoetigt
set(CMAKE_CXX_STANDARD 17)

# line 12 13 26 kommmentieren 

## vcpkg konfigurieren
if(UNIX AND NOT APPLE)
else()
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg)
        find_package(Git REQUIRED)
        execute_process(COMMAND ${GIT_EXECUTABLE} clone
            "https://github.com/microsoft/vcpkg"
            "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg")
    endif()

    if (WIN32)
        set(VCPKG_TARGET_TRIPLET "x64-windows-static")
    endif()

    include(${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

## Compileroptionen
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DNOMINMAX)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_compile_options(/MP;/utf-8)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    add_compile_options(-Wall;-Wextra)
endif()

## Abhaengigkeiten
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Modules")

## Anwendung

# Infinite_Runner mit Ihrem Infinite_Runnern ersetzen
# Falls Sie unter Windows das schwarze Konsolenfenster stoert:
# WIN32 hinter Infinite_Runner schreiben

add_executable(Infinite_Runner
src/core/engine.cpp
src/core/point.cpp
src/core/rectangle.cpp
src/core/sprite.cpp
src/core/line.cpp
src/core/image.cpp
# src/core/counter.cpp

# src/core/game_over_helper.cpp

src/game/main.cpp
src/game/inf_run.cpp
)

target_include_directories(Infinite_Runner PUBLIC
    src/core/
)
find_package(SDL2 2.0.4 REQUIRED)  # { "name": "sdl2" } in vcpkg.json
#find_package(SDL2_mixer REQUIRED) # { "name": "sdl2-mixer" }
#find_package(SDL2_image REQUIRED) # { "name": "sdl2-image" }
find_package(SDL2_ttf REQUIRED)    #{ "name": "sdl2-ttf" }
find_package(fmt REQUIRED)        # { "name": "fmt"}

target_link_libraries(Infinite_Runner PUBLIC
    SDL2::SDL2main
    #SDL2::MIXER
    #SDL2::IMAGE
    SDL2::TTF
    fmt::fmt
)
