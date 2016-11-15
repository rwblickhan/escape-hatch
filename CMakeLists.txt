cmake_minimum_required(VERSION 2.6)
project(escape-hatch)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${escape-hatch_SOURCE_DIR}/bin)
set(BIN_DIR ${escape-hatch_SOURCE_DIR}/bin)
set(INC_DIR ${escape-hatch_SOURCE_DIR}/src/inc)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -02")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

set(SOURCE_FILES src/main.cpp
                 src/GameManager.cpp
                 src/InputHandler.cpp
                 src/InventoryInterface.cpp
                 src/Item.cpp
                 src/NavigationInterface.cpp
                 src/Stage.cpp
                 src/UiManager.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${INC_DIR})

add_executable(escape-hatch ${SOURCE_FILES})
target_link_libraries(escape-hatch SDL2main SDL2)
install(TARGETS escape-hatch RUNTIME DESTINATION ${BIN_DIR})
