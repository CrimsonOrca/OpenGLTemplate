#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

class Texture
{
public:
	Texture(std::string path);
	~Texture();
	void SetUnit(int unit);
	unsigned int GetUnit() const;
	void Bind();
	void Bind(unsigned int i);
	void Unbind();
private:
	GLuint _ID;
	GLsizei _width;
	GLsizei _height;
	GLint _channels;
	GLenum _format;
	GLboolean* _data;
	int mUnit;
};

#endif _TEXTURE_H_