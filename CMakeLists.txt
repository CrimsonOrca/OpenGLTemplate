cmake_minimum_required(VERSION 3.22.1)

project("OpenGLTemplate"
		VERSION 0.1.0
		DESCRIPTION "..."
		LANGUAGES CXX)

add_subdirectory(Vendor)

add_subdirectory(Source)

add_subdirectory(Application)