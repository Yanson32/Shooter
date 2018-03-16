CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)

PROJECT("Shooter")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

ADD_EXECUTABLE("${PROJECT_NAME}" "Main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${PROJECT_NAME}" DESTINATION src)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")


add_subdirectory("include")
add_subdirectory("src")

#Define compiler features
target_compile_features("${PROJECT_NAME}"
			PRIVATE
			cxx_nullptr
			cxx_right_angle_brackets
			)


#Add includes to target
target_include_directories("${PROJECT_NAME}" PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
	)

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

#cpack
include("CPack")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Description.txt")
