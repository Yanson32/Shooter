set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Settings.h"

)
set(SUB_DIRECTORIES "Engin"
					"Events"
					"States"
					"Widget"
					"Gui"
)


#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})
endif()
