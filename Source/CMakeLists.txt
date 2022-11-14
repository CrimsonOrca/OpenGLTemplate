add_library(Window    STATIC "Window.cpp" "Window.h")
add_library(stb_image STATIC "stb_image.cpp")
add_library(Mesh      STATIC "Mesh.cpp" "Mesh.h")

target_include_directories(stb_image PUBLIC ${STB_INCLUDE_DIRS})

target_compile_features(Window    PUBLIC cxx_std_17)
target_compile_features(stb_image PUBLIC cxx_std_17)
target_compile_features(Mesh      PUBLIC cxx_std_17)

target_link_libraries(Window     glfw glad::glad) 
target_link_libraries(Mesh   glm glfw glad::glad) 

