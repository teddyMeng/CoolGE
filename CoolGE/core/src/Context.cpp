#include "Context.hpp"
#include <mutex>
#include "OGLRenderFactory.hpp"

namespace
{
	std::mutex _mutex;
}

namespace CoolGE
{
	std::unique_ptr<Context> Context::instance_;
	Context::Context()
	{
	}

	Context::~Context()
	{
	}

	Context & Context::Instance()
	{

		if (!instance_)
		{
			std::lock_guard<std::mutex> lock(_mutex);
			if (!instance_)
			{
				instance_ = std::make_unique<Context>();
			}

		}
		return *instance_;
	}

	void Context::Destroy()
	{
		if (!instance_)
		{
			instance_->DestroyAll();
			instance_.reset();
		}
	}

	void Context::LoadRenderFactory()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		GetRenderFactory(render_factory_);

	}

	RenderFactory & Context::RenderFactoryInstance()
	{
		if (!render_factory_)
		{
			std::lock_guard<std::mutex> lock(_mutex);
			if (!render_factory_)
			{
				LoadRenderFactory();
			}
			
		}
		return *render_factory_;
	}

	void Context::DestroyAll()
	{
		render_factory_.reset();
	}


}

