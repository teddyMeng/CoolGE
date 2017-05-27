#ifndef _COOLGE_CAMERA
#define _COOLGE_CAMERA

#pragma once

#include "Types.hpp"
namespace CoolGE
{
	class camera
	{
	public:
		camera();

	private:
		matrix4f view_mat_;
		matrix4f modelview_mat_;
		float fov_;
		vec3f look_at_;
		vec3f pos_;
		float far_plane_;
		float near_plane_;



	};
}


#endif