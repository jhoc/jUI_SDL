project(jUI_SDL)
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(jUI_SDL ${SOURCES})
target_link_libraries(jUI_SDL ${SDL2_LIBRARY})
install(TARGETS jUI_SDL RUNTIME DESTINATION ${BIN_DIR})

