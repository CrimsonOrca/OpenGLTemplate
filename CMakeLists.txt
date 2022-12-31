cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("OpenGLTemplate"
		VERSION 0.1.0
		DESCRIPTION "..."
		LANGUAGES CXX)

add_subdirectory(Vendor)

add_subdirectory(Source)

add_subdirectory(Application)