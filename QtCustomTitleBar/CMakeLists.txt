cmake_minimum_required(VERSION 3.16)
project(QtCustomTitleBar VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS Widgets)

qt_add_executable(QtCustomTitleBar WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    windowframe.cpp windowframe.h windowframe.ui
)
target_link_libraries(QtCustomTitleBar PRIVATE
    Qt::Core
    Qt::Gui
)


# Resources:
set(resources_resource_files
    "resources/icons/close.png"
    "resources/icons/close_light.png"
    "resources/icons/collapse_hide.png"
    "resources/icons/collapse_hide_light.png"
    "resources/icons/collapse_show.png"
    "resources/icons/collapse_show_light.png"
    "resources/icons/default_size.png"
    "resources/icons/default_size_light.png"
    "resources/icons/icon.png"
    "resources/icons/maximize.png"
    "resources/icons/maximize_light.png"
    "resources/icons/minimize.png"
    "resources/icons/minimize_light.png"
    "resources/style/appstyles.qss"
)

qt_add_resources(QtCustomTitleBar "resources"
    PREFIX
        "/recources"
    BASE
        "resources"
    FILES
        ${resources_resource_files}
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(QtCustomTitleBar PRIVATE
        Qt::Widgets
    )
endif()

install(TARGETS QtCustomTitleBar
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
