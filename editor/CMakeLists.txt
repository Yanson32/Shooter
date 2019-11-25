cmake_minimum_required(VERSION "3.1.0")
PROJECT("Editor")

add_library("${PROJECT_NAME}" "")

#Add includes to target
target_include_directories("${PROJECT_NAME}" PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
	)

add_subdirectory("include")
add_subdirectory("src")

find_package(TGUI REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${TGUI_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${TGUI_LIBRARY})
