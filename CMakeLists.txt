cmake_minimum_required(VERSION 3.23)
project(Chapitre_09)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(libdio
        GIT_REPOSITORY https://github.com/HEIGVD-PRG1-F-2022/libdio.git
        GIT_TAG v0.2.1
        )
FetchContent_MakeAvailable(libdio)

add_subdirectory(Exo_9_5)
add_subdirectory(Exo_9_6)
add_subdirectory(Exo_9_7)
add_subdirectory(Exo_9_8)
add_subdirectory(Exo_9_10)
add_subdirectory(Exo_9_14)
add_subdirectory(Exo_9_15)
add_subdirectory(Exo_9_16)
