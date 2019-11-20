add_executable("${PROJECT_NAME}" "Main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

add_subdirectory("include")
add_subdirectory("src")

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 14)

#Define compiler features
target_compile_features("${PROJECT_NAME}"
			PRIVATE
			cxx_nullptr
			cxx_right_angle_brackets
			cxx_auto_type
			cxx_decltype
			)


#Add includes to target
target_include_directories("${PROJECT_NAME}" PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
	)

target_link_libraries("${PROJECT_NAME}" PUBLIC Box2D)

#Find GameUtiliites packages
find_package(GameUtilities COMPONENTS Core Event Engin REQUIRED)
target_link_libraries("${PROJECT_NAME}" PRIVATE GU::Core GU::Event GU::Engin)

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${SFML_LIBRARIES})

find_package(TGUI REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${TGUI_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${TGUI_LIBRARY})

find_package(Boost COMPONENTS filesystem REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC ${Boost_LIBRARIES})
target_include_directories("${PROJECT_NAME}" PUBLIC ${Boost_INCLUDE_DIRS})

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

configure_file("${CMAKE_SOURCE_DIR}/cmake/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/config.h")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/config.h" DESTINATION "include")
add_definitions(-DDEBUG)

