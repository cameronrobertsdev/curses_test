add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
	PRIVATE
		objects.hpp
		objects.cpp
		main.cpp
)

find_package(Curses)
if(Curses_FOUND AND NOT TARGET Curses::Curses)
	add_library(Curses::Curses INTERFACE IMPORTED)
	set_target_properties(
		Curses::Curses
		PROPERTIES
			INTERFACE_LINK_LIBRARIES "${CURSES_LIBRARIES}"
			INTERFACE_INCLUDE_DIRECTORIES "${CURSES_INCLUDE_DIRS}"
	)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Curses::Curses)
