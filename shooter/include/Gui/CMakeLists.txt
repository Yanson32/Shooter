set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/IntroPanel.h"
	    "${CMAKE_CURRENT_SOURCE_DIR}/MapLoader.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/NewLevelSettingsPanel.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/GuiBase.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/PlayerInfo.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/id.h"

)

set(SUB_DIRECTORIES "Editor" "Options"
)

foreach(VAR ${SUB_DIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
endif()
