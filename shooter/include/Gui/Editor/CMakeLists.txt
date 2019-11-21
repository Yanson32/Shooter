set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/MapCreatorPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorGeneralPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorLayersPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorObjectPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/EditorPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/Grid.h"
)

set(RELATIVE_PATH "include")
set(SUB_DIRECTORIES ""
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
	install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif()
