set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/IntroPanel.cpp"
	    "${CMAKE_CURRENT_SOURCE_DIR}/MapLoader.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/NewLevelSettingsPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/GuiBase.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/PlayerInfo.cpp"
)

set(SUB_DIRECTORIES "Editor" "Options"
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
endif()
