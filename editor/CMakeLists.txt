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

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#Find and link TGUi
find_package(TGUI 0.8 REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC tgui)

find_package(GameUtilities COMPONENTS Core Event Engin REQUIRED)
target_link_libraries("${PROJECT_NAME}" PRIVATE GU::Core GU::Event GU::Engin)

find_package(Boost COMPONENTS filesystem REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC ${Boost_LIBRARIES})
target_include_directories("${PROJECT_NAME}" PUBLIC ${Boost_INCLUDE_DIRS})