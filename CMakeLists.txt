cmake_minimum_required(VERSION 3.10) 
project( timer )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set(SOURCES
    main.cpp
    TempoMedio.cpp
    Timer.cpp
)

add_executable( timer ${SOURCES} )
