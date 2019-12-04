set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/EditorPanel.h"
)

set(SUB_DIRECTORIES ""
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
endif()
