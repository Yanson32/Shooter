set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/ECS.h"

)
set(SUB_DIRECTORIES 	"Components"
			"Systems"
)


#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})
endif()
