#ifndef _COOLGE_PRECLARE
#define _COOLGE_PRECLARE
#include <memory>

#pragma once
namespace CoolGE
{
	//typedef int32_t   Int32;
	//typedef uint32_t   Uint32;
	//typedef int16_t   Int16;
	//typedef uint16_t   Uint16;
	//typedef int8_t   Int8;
	//typedef uint8_t   Uint8;

	class Texture;
	typedef std::shared_ptr<Texture> TexturePtr;
}
#endif
