FILE_PATH = "../Vendor/glad/CMakeLists.txt"

WRITE_MODE = 'w'

SCRIPT = \
"""
cmake_minimum_required (VERSION 3.22.1)

project(glad)

set(HEADER_LIST 
	"./include/glad/glad.h" 
	"./include/KHR/khrplatform.h")

add_library(glad STATIC "./src/glad.c" ${HEADER_LIST})

target_include_directories(glad PUBLIC "./include")
""" 

with open(FILE_PATH, WRITE_MODE) as FileObject:
	FileObject.write(SCRIPT)
	FileObject.close()