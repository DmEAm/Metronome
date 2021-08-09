cmake_minimum_required(VERSION 3.14)

project(AudioAnalysisPlugin LANGUAGES CXX)

include(GenerateExportHeader)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Charts Multimedia Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Charts Multimedia Quick REQUIRED)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_BINARY_DIR}/*.h)
file(GLOB RESOURCE_FILES ${PROJECT_SOURCE_DIR}/*.qrc)

qt5_add_resources(PLUGIN_RESOURCES ${RESOURCE_FILES})
set(PROJECT_SOURCES
    ${SOURCE_FILES}
    ${PLUGIN_RESOURCES}
    ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

generate_export_header(${PROJECT_NAME} BASE_NAME AUDIO_ANALYSIS_PLUGIN)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Multimedia
    Tempo)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${Tempo_SOURCE_DIR})

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_LIST_DIR}/qmldir
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/qmldir
)
