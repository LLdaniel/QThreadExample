cmake_minimum_required(VERSION 3.16)
project(QThreadExample VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
## set for debug
#set(CMAKE_CXX_FLAGS "-g")

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(QThreadExample MANUAL_FINALIZATION
  A.cxx A.h
  B.cxx B.h
  main.cxx
  )
  

# for cmake version > 3.19 (s. https://doc.qt.io/qt-6//qt-set-finalizer-mode.html)
qt_set_finalizer_mode(QThreadExample ENABLE MODES static_plugins)
qt_finalize_target(QThreadExample)

target_compile_definitions(QThreadExample PRIVATE
  QT_DEPRECATED_WARNINGS
  )

target_link_libraries(QThreadExample PRIVATE
  Qt::Core
  Qt::Gui
  Qt::Widgets
  )

if((QT_VERSION_MAJOR GREATER 4))
  target_link_libraries(QThreadExample PRIVATE
    Qt::Widgets
    )
endif()

install(TARGETS QThreadExample
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${HOME}/Documents/QThreadExample/
  )

qt_generate_deploy_app_script(
  TARGET QThreadExample
  FILENAME_VARIABLE deploy_script
  NO_UNSUPPORTED_PLATFORM_ERROR
  )
install(SCRIPT ${deploy_script})
