add_executable(Application "Application.cpp")

target_include_directories(Application PRIVATE "${OpenGLTemplate_SOURCE_DIR}/Include")

add_custom_target(Assets ALL
                  COMMAND ${CMAKE_COMMAND} -E copy_directory
                  ${OpenGLTemplate_SOURCE_DIR}/Assets
                  ${OpenGLTemplate_BINARY_DIR}/Application/Assets
                  COMMENT "COPYING ASSETS FOLDER TO ${OpenGLTemplate_BINARY_DIR}/Application/Assets")

add_dependencies(Application Assets)

target_link_libraries(Application PRIVATE graphics-template)