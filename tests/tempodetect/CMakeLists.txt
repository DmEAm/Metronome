cmake_minimum_required(VERSION 3.5)

project(TempoDetectionTestCase LANGUAGES CXX)

find_package(Qt5 COMPONENTS Test Multimedia REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

include_directories(${Tempo_SOURCE_DIR})

file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/*.wav)
file(COPY ${TEST_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME} tst_tempodetectiontestcase.cpp test.qrc)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Test Qt5::Multimedia Tempo)

