cmake_minimum_required(VERSION 3.14)

project(Metronome VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CLANG_TIDY NAMES "clang-tidy")

if (CLANG_TIDY)
#    set(CMAKE_CXX_CLANG_TIDY clang-tidy)
endif ()

#set(CMAKE_AUTOGEN_VERBOSE ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")

    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Multimedia REQUIRED)

add_subdirectory(plugins)
add_subdirectory(lib)
include_directories(plugins)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/*.hpp)
file(GLOB RESOURCE_FILES ${PROJECT_SOURCE_DIR}/*.qrc)

file(COPY components DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
set(COMPONENTS_RESOURCE ${CMAKE_CURRENT_BINARY_DIR}/components/components.qrc)

file(GLOB COMPONENTS_SOURCES components/*.qml)
set(COMPONENTS_RESOURCE_CONTENT "")
set(COMPONENTS_QML_DIR_CONTENT "")

foreach (component ${COMPONENTS_SOURCES})
    get_filename_component(name_we ${component} NAME_WE)
    get_filename_component(name ${component} NAME)
    string(APPEND COMPONENTS_RESOURCE_CONTENT <file>${name}</file>)
    string(APPEND COMPONENTS_QML_DIR_CONTENT "${name_we} qrc:/components/${name}\n")
endforeach ()

file(WRITE ${COMPONENTS_RESOURCE}
"<RCC>
    <qresource prefix=\"/components\">
        ${COMPONENTS_RESOURCE_CONTENT}
    </qresource>
</RCC>")

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/components/qmldir ${COMPONENTS_QML_DIR_CONTENT})

set(PROJECT_SOURCES
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
        ${COMPONENTS_RESOURCE}
        ${HEADER_FILES})

if (ANDROID)
    add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
else ()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif ()

target_compile_definitions(${PROJECT_NAME}
        PUBLIC
        PROJECT_NAME="${PROJECT_NAME}"
        PROJECT_VERSION="${PROJECT_VERSION}"
        PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        $<TARGET_PROPERTY:PickerPlugin,INCLUDE_DIRECTORIES>)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Multimedia
        PUBLIC
        Metronome::TapperPlugin
        Metronome::PickerPlugin
        Metronome::PlayerPlugin)
