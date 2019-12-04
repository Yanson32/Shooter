set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Id.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/IntroState.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/PlayState.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/MapCreatorState.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/StateBase.h"
)
set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})
endif()
