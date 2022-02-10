cmake_minimum_required(VERSION 3.10)

project(SuperKley)

set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(StraitXPackages/Base)
add_subdirectory(StraitXPackages/2D)
add_subdirectory(StraitXPackages/ImGui)

set(SAMPLE_SOURCES
    "sources/main.cpp"
    "sources/Application.cpp"
    "sources/Bullet.cpp"
    "sources/GameObject.cpp"
    "sources/Level.cpp"
    "sources/Player.cpp"
    "sources/RectangleShape.cpp")

set(SAMPLE_INCLUDE
    "sources/"
)

add_executable(SuperKley ${SAMPLE_SOURCES})
target_link_libraries(SuperKley StraitXBase StraitX2D StraitXImGui)
target_include_directories(SuperKley
    PUBLIC ${SAMPLE_INCLUDE}
)