cmake_minimum_required(VERSION 3.5)

project(TempoDetectionTestCase LANGUAGES CXX)

find_package(Qt5 COMPONENTS Test Multimedia REQUIRED)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

#https://gstreamer.freedesktop.org/documentation/tutorials/basic/debugging-tools.html?gi-language=c
message(NOTICE "Set GST_DEBUG env var for more detailed GStreamer lib output")

include_directories(${Tempo_SOURCE_DIR})

file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/*.wav)
file(COPY ${TEST_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME} tst_tempodetectiontestcase.cpp)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_directories(${PROJECT_NAME} PRIVATE ${ESSENTIA_LINK_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Test
    Qt5::Multimedia
    Tempo
    essentia)

add_dependencies(${PROJECT_NAME} Essentia)

target_include_directories(${PROJECT_NAME} PRIVATE ${ESSENTIA_INCLUDE_DIR})
