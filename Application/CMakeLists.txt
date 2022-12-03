add_executable (Application "Application.cpp")

target_include_directories(Application PRIVATE "${OpenGLTemplate_SOURCE_DIR}/Include")

target_link_libraries(Application PRIVATE graphics-template)