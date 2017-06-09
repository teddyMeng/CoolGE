#ifndef _COOLGE_TEXTURE
#define _COOLGE_TEXTURE

#pragma once
#include "Types.hpp"
namespace CoolGE
{
	enum TextureFilterType
	{
		TFT_LINEAR,
		TFT_BILINEAR,
		TFT_TRILINEAR,
		TFT_MAX,
	};

	enum TextureAddress
	{
		TA_WRAP,
		TA_MIRROR,
		TA_CLAMP,
		TA_MAX,
	};

	enum PixelFormat
	{
		PF_RGBA8888,
	};

	class Texture
	{
	public:
		explicit Texture();
		virtual ~Texture();
	public:
		uint32_t GetSize();
		uint32_t GetWidth();
		uint32_t GetHeight();
		PixelFormat GetPixelFormat();
	public:



	private:
		uint32_t size_;
		uint32_t width_;
		uint32_t height_;
		PixelFormat pixel_format_;		
	};
	
}


#endif
