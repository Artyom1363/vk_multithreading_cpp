project(any_app)

set(EXE_SOURCES
	main.cpp
)

add_executable(check ${EXE_SOURCES})

# target_link_libraries(check PRIVATE any_lib)
set_target_properties(check PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#message(STATUS ${CMAKE_SOURCE_DIR} ${SOME_VAL})
#message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(check PUBLIC ${CMAKE_SOURCE_DIR}/include)

#SET(SOME_VAL2 dfjkdsfjk)
