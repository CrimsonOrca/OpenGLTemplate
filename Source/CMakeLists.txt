set(SOURCE_LIST
	"Window.cpp"
	"Mesh.cpp"
	"Quad.cpp"
	"Shader.cpp"
	"VertexArray.cpp"
	"VertexBuffer.cpp"
	"IndexBuffer.cpp"
	"Texture.cpp"
	"Transformation.cpp"
	"Camera.cpp"
	"Timer.cpp"
	"Sphere.cpp"
	"Cube.cpp"
	"Renderer.cpp"
	"stb_image.cpp")

set(HEADER_LIST
	"Window.h"
	"Mesh.h"
	"Quad.h"
	"Shader.h"
	"VertexArray.h"
	"VertexBuffer.h"
	"IndexBuffer.h"
	"Texture.h"
	"Transformation.h"
	"Camera.h"
	"Timer.h"
	"Sphere.h"
	"Cube.h"
	"Renderer.h"
	"Constants.h"
	"Vertex.h"
	"Buffer.h"
)

add_library(graphics-template STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_compile_features(graphics-template PUBLIC cxx_std_20)

target_include_directories(graphics-template PUBLIC "${OpenGLTemplate_SOURCE_DIR}/Vendor/stb")

target_link_libraries(graphics-template PUBLIC glm::glm glfw glad) 