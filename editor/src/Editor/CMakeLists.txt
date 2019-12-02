set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Editor.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MapCreatorPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Layer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Grid.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Tile.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorGeneralPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorLayersPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorObjectPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PanelBase.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/ContentPane.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/PropertiesPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LayerPropertiesPanel.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LayersListBox.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Functions.cpp"
)
set(SUB_DIRECTORIES ""
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
	install(FILES ${FILES} DESTINATION "${CMAKE_INSTALL_PREFIX}/${RELATIVE_PATH}")
endif()
