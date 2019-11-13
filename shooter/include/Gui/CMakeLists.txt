set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/PanelBase.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/IntroPanel.h"

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
