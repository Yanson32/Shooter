set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/OptionsPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/GeneralPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/ControlPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/SoundPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/MultiPlayerSettingsPanel.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/DevSettingsPanel.cpp"
)

set(SUB_DIRECTORIES ""
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
endif()
