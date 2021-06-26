# Add executable called "learnOpenGl" that is built from the source files
add_executable (learnOpenGl main.cpp)

target_sources (learnOpenGl PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/glad.c 
	${CMAKE_CURRENT_SOURCE_DIR}/learningPhases/lp-common.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/learningPhases/main-create-window.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/learningPhases/main-hello-triangle-line.cpp
)

include_directories ( 
	${CMAKE_CURRENT_SOURCE_DIR}/include 
	${CMAKE_CURRENT_SOURCE_DIR}/externalInclude 
	${CMAKE_CURRENT_SOURCE_DIR}/learningPhases 
)

target_link_libraries (learnOpenGl ${CMAKE_CURRENT_SOURCE_DIR}/externalLibs/GLFW/x64/glfw3.lib )
