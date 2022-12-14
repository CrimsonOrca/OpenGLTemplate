#include "Texture.h"

Texture::Texture(std::string path)
	: _ID       {0}
	, _width    {0}
	, _height   {0}
	, _channels {0}
	, _format   {0}
	, _data     {nullptr}
	, mUnit     {-1}
{
	stbi_set_flip_vertically_on_load(true);

	unsigned char* _data = stbi_load(path.c_str(), &_width, &_height, &_channels, 0);
	if (_data)
	{
		switch (_channels)
		{
			case 1:
				_format = GL_RED;
				break;
			case 2:
				_format = GL_RG;
				break;
			case 3:
				_format = GL_RGB;
				break;
			case 4:
				_format = GL_RGBA;
				break;
			default:
				std::cout << "ERROR - UNKNOWN IMAGE FORMAT..." << std::endl;
		}

		glGenTextures(1, &_ID);
		glBindTexture(GL_TEXTURE_2D, _ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, _format, _width, _height, 0, _format, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(_data);
	}
	else
		std::cout << "ERROR - FAILED TO LOAD TEXTURE: " << path << std::endl;
}

Texture::~Texture()
{
	glDeleteTextures(1, &_ID);
}

void Texture::SetUnit(int unit)
{
	if (unit >= 0)
		mUnit = unit;
	else
		std::cout << "TEXTURE UNIT CANNOT BE NEGATIVE...\n";
}

unsigned int Texture::GetUnit() const
{
	return mUnit;
}

void Texture::Bind()
{
	if (mUnit >= 0)
	{
		glActiveTexture(GL_TEXTURE0 + mUnit);
		glBindTexture(GL_TEXTURE_2D, _ID);
	}
	else
	{
		std::cout << "TEXTURE UNIT NOT SET...\n";
	}
}

void Texture::Bind(unsigned int i)
{
	glActiveTexture(GL_TEXTURE0 + i);
	glBindTexture(GL_TEXTURE_2D, _ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}