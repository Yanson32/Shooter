set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Id.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/Events.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/EventBase.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/SFEventHandler.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/ShowGrid.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/SnapToGrid.h"
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
