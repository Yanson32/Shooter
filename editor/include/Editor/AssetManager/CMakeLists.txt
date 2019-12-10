set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/AssetManager.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/AssetManagerImagePanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/AssetManagerTilesheetPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/AssetManagerEffectPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/AssetManagerMusicPanel.h"
)
set(SUB_DIRECTORIES ""
)

set(RELATIVE_PATH "include/Editor/AssetManager")

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
