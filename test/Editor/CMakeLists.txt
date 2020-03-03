set(FILES "MapTest"

)

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


#Create test runners
foreach(LOOP_VAR ${FILES})
	add_executable("${LOOP_VAR}" "${LOOP_VAR}.cpp" )
	set_target_properties("${LOOP_VAR}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
	target_link_libraries("${LOOP_VAR}" PRIVATE Editor sfml-system sfml-window sfml-graphics sfml-audio sfml-network Catch2::Catch2)
	catch_discover_tests("${LOOP_VAR}")
endforeach()

