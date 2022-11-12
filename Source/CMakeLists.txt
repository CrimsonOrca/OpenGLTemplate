add_library(Window STATIC "Window.cpp" "Window.h")
add_library(stb_image STATIC "stb_image.cpp")

target_include_directories(stb_image PUBLIC ${STB_INCLUDE_DIRS})

target_compile_features(Window PUBLIC cxx_std_17)
target_compile_features(stb_image PUBLIC cxx_std_17)

target_link_libraries(Window glfw glad::glad) 

