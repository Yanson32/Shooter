CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)

PROJECT("Shooter")

ADD_EXECUTABLE("${PROJECT_NAME}" "Main.cpp")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

find_package(GameUtilities REQUIRED)
# and for each of your dependent executable/library targets:
target_link_libraries("${PROJECT_NAME}" PUBLIC "GameUtilities")


find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${SFML_LIBRARIES})

find_package(Box2D REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${BOX2D_INCLUDE_DIRS})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${BOX2D_LIBRARIES})

find_package(TGUI 0.7 REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${TGUI_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${TGUI_LIBRARY})
