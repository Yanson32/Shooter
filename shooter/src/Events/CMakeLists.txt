set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/EventBase.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/EventManager.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/SFEventHandler.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/ShowGrid.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/SnapToGrid.cpp"
)
set(SUB_DIRECTORIES ""
)

set(RELATIVE_PATH "src/Events")

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
