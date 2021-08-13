project(Tempo)

set(CMAKE_CXX_STANDARD 11)

include(GenerateExportHeader)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Multimedia REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_BINARY_DIR}/*.h)

set(PROJECT_SOURCES
    ${SOURCE_FILES}
    ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

generate_export_header(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${EIGEN3_INCLUDE_DIR}
        ${ESSENTIA_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} PRIVATE ${ESSENTIA_LINK_DIR})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Multimedia
    PUBLIC
        essentia)

target_include_directories(${PROJECT_NAME} PRIVATE ${AVCODEC_INCLUDE_DIR})
