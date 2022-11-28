add_executable (Application "Application.cpp")

target_include_directories(Application PRIVATE "${OpenGLTemplate_SOURCE_DIR}/Source")

target_compile_features(Application PRIVATE cxx_std_17)

target_link_libraries(Application PRIVATE GRAPHICS_TEMPLATE)