set(SOURCE_FILES
	Window.cpp
	Mesh.cpp
	Rectangle.cpp
	Shader.cpp
	VertexArray.cpp
	VertexBuffer.cpp
	IndexBuffer.cpp
	Texture.cpp
	Transformation.cpp
	stb_image.cpp
	Camera.cpp
)

set(HEADER_FILES
	Window.h
	Mesh.h
	Rectangle.h
	Shader.h
	VertexArray.h
	VertexBuffer.h
	IndexBuffer.h
	Texture.h
	Transformation.h
	Camera.h
	Constants.h
	Vertex.h
)

add_library(GRAPHICS_TEMPLATE STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(GRAPHICS_TEMPLATE PUBLIC ${STB_INCLUDE_DIRS})

target_compile_features(GRAPHICS_TEMPLATE PUBLIC cxx_std_17)

set(LIBRARIES glm::glm glfw glad::glad)

target_link_libraries(GRAPHICS_TEMPLATE PUBLIC ${LIBRARIES}) 