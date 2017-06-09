#ifndef _COOLGE_RENDERFACTORY
#define _COOLGE_RENDERFACTORY

#pragma once

#include "PreDeclare.hpp"
#include "Config.hpp"
namespace CoolGE
{
	class RenderFactory
	{
	public:
		virtual TexturePtr MakeTexture() = 0;

	};

}
#endif 