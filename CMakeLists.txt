cmake_minimum_required(VERSION 3.16)

project(ALIVE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
)

set(PROJECT_SOURCES
        main.cpp
        homepage.cpp
        homepage.h
        homepage.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ALIVE
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        agents.h agents.cpp
        resourses.qrc


        rolepage.h rolepage.cpp rolepage.ui
        roleedit.h roleedit.cpp
        mybutton.h mybutton.cpp
        gamestate.h gamestate.cpp
        shoppage.h shoppage.cpp shoppage.ui
        gamepage.h gamepage.cpp gamepage.ui
        rolewidget.h rolewidget.cpp
        history.h history.cpp
        gamelosebox.h gamelosebox.cpp gamelosebox.ui
        buffpage.h buffpage.cpp buffpage.ui
        gamepausepage.h gamepausepage.cpp gamepausepage.ui
        gamewinbox.h gamewinbox.cpp gamewinbox.ui



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ALIVE APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ALIVE SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ALIVE
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ALIVE PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ALIVE)
endif()
set_target_properties(ALIVE PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ALIVE
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ALIVE)
endif()
