set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Settings.cpp"
)
set(SUB_DIRECTORIES "Engin"
					"Events"
					"States"
					"Widget"
					"Gui"
)

set(RELATIVE_PATH "src")
#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
