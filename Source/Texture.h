#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

const GLenum TEXTURE_1D { GL_TEXTURE_1D };
const GLenum TEXTURE_2D { GL_TEXTURE_2D };
const GLenum TEXTURE_3D { GL_TEXTURE_3D };

class Texture
{
public:
	Texture(std::string path);
	~Texture();
	void Bind(int i);
private:
	GLuint     _ID;
	GLsizei    _width;
	GLsizei    _height;
	GLint      _channels;
	GLenum     _format;
	GLboolean* _data;
};

#endif _TEXTURE_H_ // !_TEXTURE_H_