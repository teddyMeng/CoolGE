#ifndef _COOLGE_CONTEXT
#define _COOLGE_CONTEXT

#include "PreDeclare.hpp"
#include "Config.hpp"
#include "RenderFactory.hpp"
#include <memory>

#pragma once
namespace CoolGE
{
	class Context
	{
	public:
		Context();
		~Context();
		static Context& Instance();
		static void Destroy();
	public:
		void LoadRenderFactory();
	public:
		RenderFactory& RenderFactoryInstance();
	private:
		void DestroyAll();

	private:
		static std::unique_ptr<Context> instance_;
		std::unique_ptr<RenderFactory> render_factory_;

	};
}

#endif

