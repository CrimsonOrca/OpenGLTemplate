cmake_minimum_required(VERSION 3.22.1)

project(
	"OpenGLTemplate"
	VERSION 1
	DESCRIPTION "..."
	LANGUAGES CXX
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
find_package(assimp CONFIG REQUIRED)

include_directories(Shaders)
include_directories(Textures)

add_subdirectory(Application)
add_subdirectory(Source)
