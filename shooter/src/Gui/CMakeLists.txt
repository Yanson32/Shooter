set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/PanelBase.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/ControlPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/DevPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/GeneralPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/OptionsPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/SoundPanel.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/IntroPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/TimerPanel.cpp"
			#"${CMAKE_CURRENT_SOURCE_DIR}/ScorePanel.cpp"
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
