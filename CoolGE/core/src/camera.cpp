#include "Camera.hpp"
#include "Math.hpp"

namespace CoolGE
{
	Camera::Camera()
	{
		this->ViewParams(Vec3f(0, 0, 0), Vec3f(0, 0, 1));
		this->ProjParams(PI / 4, 1, 1, 1000);
	}

	void Camera::ViewParams(Vec3f const & eye_pos, Vec3f const & look_at)
	{
		look_at_ = look_at;
		pos_ = eye_pos;
		//view_mat_ = MathLib::lookatLH(eye_pos, look_at, Vec3f(0, 1, 0));

	}

	void Camera::ProjParams(float fov, float aspect, float near, float far)
	{
		type_ = PRT_PERSPECTIVE;
		fov_ = fov;
		far_plane_ = far;
		near_plane_ = near;
		proj_mat_ = MathLib::perspectiveLH(fov, aspect, near, far);
	}

//	void ProjOrthoParams(float w, float h, float near, float far);
//	void ProjOrthoParams(float left, float right, float top, float bottom, float near, float far);
//
//public:
//	ProjectionType GetProjectionType();

}