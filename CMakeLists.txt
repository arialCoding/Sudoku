cmake_minimum_required(VERSION 3.20)

project(Sudoku)

set (linkLibs SDL2main SDL2 SDL2_image SDL2_ttf)

if(WIN32)
    set (linkLibs mingw32 ${linkLibs})
endif()

link_directories(vendor/SDL2/lib)

file (GLOB_RECURSE ENGINE_SRCS source/Engine/*.cpp)

add_library(Engine ${ENGINE_SRCS})
target_include_directories(Engine PUBLIC vendor/SDL2/include source/Engine/include)
target_link_libraries(Engine PUBLIC ${linkLibs})

add_library(Game source/Game/Game.cpp)
target_include_directories(Game PUBLIC vendor/SDL2/include source/Engine/include)
target_link_libraries(Game PUBLIC ${linkLibs} Engine)

add_executable(Sudoku source/main.cpp)
target_include_directories(Sudoku PUBLIC vendor/SDL2/include source/Engine/include)
target_link_libraries(Sudoku PUBLIC ${linkLibs} Engine Game)

add_custom_command(
    TARGET Sudoku POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/source/resource $<TARGET_FILE_DIR:Sudoku>/resource
)

file(GLOB SDL2_DLLS "${CMAKE_SOURCE_DIR}/vendor/SDL2/bin/*.dll")
foreach(DLL ${SDL2_DLLS})
    add_custom_command(
        TARGET Sudoku POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${DLL} $<TARGET_FILE_DIR:Sudoku>
    )
endforeach()