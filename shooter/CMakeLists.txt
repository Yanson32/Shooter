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
target_link_libraries("${PROJECT_NAME}" PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#Find and link TGUi
find_package(TGUI 0.8 REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC tgui)

find_package(Boost COMPONENTS filesystem REQUIRED)
target_link_libraries("${PROJECT_NAME}" PUBLIC ${Boost_LIBRARIES})
target_include_directories("${PROJECT_NAME}" PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries("${PROJECT_NAME}" PUBLIC Editor)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

configure_file("${CMAKE_SOURCE_DIR}/cmake/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/config.h")

add_definitions(-DDEBUG)

#copy assets folder to build directory for multi config generators
if(CMAKE_CONFIGURATION_TYPES)
foreach(TYPE ${CMAKE_CONFIGURATION_TYPES})
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${TYPE}/Assets/")
endforeach()
#copy assets folder to build direcotry for single config generators
else(NOT CMAKE_CONFIGURATION_TYPES)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Assets/")
endif()


