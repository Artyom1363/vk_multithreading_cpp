cmake_minimum_required(VERSION 3.16)

project(hm01)
# message("USER_LIB_INCLUDE_DIRS = ${USER_LIB_INCLUDE_DIRS}")
message("PROJECT_NAME = ${PROJECT_NAME}")
message(STATUS ${CMAKE_BINARY_DIR})
# set(SOME_VAL 21223)

# add_subdirectory(lib/)
add_subdirectory(exe/)
add_subdirectory(test/unit)