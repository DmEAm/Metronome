cmake_minimum_required(VERSION 3.14)

project(PlayerPlugin LANGUAGES CXX)

include(GenerateExportHeader)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Widgets Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Widgets Multimedia REQUIRED)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/*.hpp)
file(GLOB RESOURCE_FILES ${PROJECT_SOURCE_DIR}/*.qrc)

set(PROJECT_SOURCES
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
        ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
add_library(Metronome::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::Widgets
    PUBLIC
        Metronome::Core
        Metronome::PickerPlugin)

generate_export_header(${PROJECT_NAME} BASE_NAME PLAYER_PLUGIN)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_BINARY_DIR}
        $<TARGET_PROPERTY:Core,SOURCE_DIR>
        $<TARGET_PROPERTY:PickerPlugin,INCLUDE_DIRECTORIES>)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_LIST_DIR}/qmldir
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/qmldir
)
