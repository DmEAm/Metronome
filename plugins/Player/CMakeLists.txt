cmake_minimum_required(VERSION 3.14)

project(PlayerPlugin LANGUAGES CXX)

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

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR}} DIRECTORY)
set(CORE_INCLUDE_DIR "${PARENT_DIR}/core")
include_directories("${CORE_INCLUDE_DIR}")

set(PROJECT_SOURCES
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
        ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::Widgets
    PUBLIC
        core)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${CORE_INCLUDE_DIR}
        $<TARGET_PROPERTY:PickerPlugin,INCLUDE_DIRECTORIES>)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_LIST_DIR}/qmldir
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/qmldir
)
