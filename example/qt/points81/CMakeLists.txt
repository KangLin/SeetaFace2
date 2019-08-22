cmake_minimum_required(VERSION 2.8)

project(points81)

#需要的QT组件
SET(QT_COMPONENTS Core Gui Widgets Xml Network Multimedia)
find_package(Qt5 COMPONENTS ${QT_COMPONENTS})

#打开 qt 编译工具
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_VERBOSE_MAKEFILE ON)

FOREACH(_COMPONENT ${QT_COMPONENTS})
    SET(QT_LIBRARIES ${QT_LIBRARIES} ${Qt5${_COMPONENT}_LIBRARIES})
ENDFOREACH()

SET(QT_INSTALL_DIR "${Qt5_DIR}/../../..")

set(SRC_FILES
    main.cpp
    MainWindow.cpp    
    FrmDisplay.cpp
    CameraQtCaptureVideoFrame.cpp
    )

set(HEADER_FILES
    MainWindow.h    
    FrmDisplay.h
    CameraQtCaptureVideoFrame.h
    )

set(UI_FILES
    MainWindow.ui
    FrmDisplay.ui
    )

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES}) 
