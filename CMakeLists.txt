cmake_minimum_required(VERSION 3.22.1)

project(
	"OpenGLTemplate"
	VERSION 0.1.0
	DESCRIPTION "..."
	LANGUAGES CXX
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_c_lexer.h" "stb_image.h")
find_package(assimp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_subdirectory(Application)
add_subdirectory(Source)
