#ifndef _COOLGE_CAMERA
#define _COOLGE_CAMERA

#pragma once

#include "Types.hpp"
namespace CoolGE
{
	class Camera
	{
	public:
		Camera();
	public:
		void ViewParams(Vec3f const & eye_pos, Vec3f const & look_at);
		void ProjParams(float fov, float aspect, float near, float far);
		void ProjOrthoParams(float w, float h, float near, float far);
		void ProjOrthoParams(float left, float right, float top, float bottom, float near, float far);

	public:
		ProjectionType GetProjectionType();



	private:
		ProjectionType type_;
		Matrix4f view_mat_;
		Matrix4f proj_mat_;
		float fov_;
		Vec3f look_at_;
		Vec3f pos_;
		float far_plane_;
		float near_plane_;



	};
}


#endif