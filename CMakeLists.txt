CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)

PROJECT("Shooter")

#Set default compiler flags
if(NOT DEFINED ${PROJECT_NAME}_IS_FIRST_RUN)
	set(${PROJECT_NAME}_IS_FIRST_RUN False CACHE INTERNAL "Used to determine if current run is first run")

	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra -Wall -pedantic -pedantic-errors" CACHE STRING "Compiler variables for debug mode" FORCE)
	endif()
endif()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("extlibs")
add_subdirectory("editor")
add_subdirectory("shooter")
#cpack
include("CPack")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Description.txt")

option(EDITOR_TESTING "Set to true if you want to build unit tests" false)
if(EDITOR_TESTING)
	add_subdirectory("test")
endif()
