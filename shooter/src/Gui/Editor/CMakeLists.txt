set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/MapCreatorPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorGeneralPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorLayersPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorObjectPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/Grid.cpp"
)

set(RELATIVE_PATH "src")
set(SUB_DIRECTORIES ""
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
	install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif()
