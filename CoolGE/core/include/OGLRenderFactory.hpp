#ifndef _COOLGE_OGLRENDERFACTORY
#define _COOLGE_OGLRENDERFACTORY
#pragma once

#include "RenderFactory.hpp"
namespace CoolGE
{
	class OGLRenderFactory :public RenderFactory
	{
	public:
		TexturePtr MakeTexture();

	};
}

#ifdef _OPENGL
void GetRenderFactory(std::unique_ptr<CoolGE::RenderFactory>& ptr)
{
	ptr = std::make_unique<CoolGE::OGLRenderFactory>();
}
#endif



#endif

