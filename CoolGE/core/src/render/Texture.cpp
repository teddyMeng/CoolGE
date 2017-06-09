#include "Texture.hpp"

namespace CoolGE
{
	Texture::Texture()
		: size_(0), width_(0), height_(0), pixel_format_(PF_RGBA8888)
	{

	}
	Texture::~Texture()
	{

	}

	uint32_t Texture::GetSize()
	{
		return size_;
	}

	uint32_t Texture::GetWidth()
	{
		return width_;
	}

	uint32_t Texture::GetHeight()
	{
		return height_;
	}

	PixelFormat Texture::GetPixelFormat()
	{
		return pixel_format_;
	}

}