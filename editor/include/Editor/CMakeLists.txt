set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/Editor.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/MapCreatorPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/Map.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/Tile.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/Grid.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorGeneralPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorLayersPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/EditorObjectPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/PanelBase.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/ContentPane.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/PropertiesPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/LayerPropertiesPanel.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/LayersListBox.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/Functions.h"
)
set(SUB_DIRECTORIES "Layers"
)

set(RELATIVE_PATH "include")

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
