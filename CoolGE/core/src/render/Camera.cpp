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
		view_mat_ = MathLib::lookatLH(eye_pos, look_at, Vec3f(0, 1, 0));
	}

	void Camera::ProjParams(float fov, float aspect, float near, float far)
	{
		type_ = PRT_PERSPECTIVE;
		fov_ = fov;
		proj_mat_ = MathLib::perspectiveLH(fov, aspect, near, far);
	}

	void Camera::ProjOrthoParams(float w, float h, float near, float far)
	{
		type_ = PRT_ORTHOGRAPHIC;
		proj_mat_ = MathLib::orthoLH(near, far, -w / 2, w / 2, -h / 2, h / 2);
	}
	void Camera::ProjOrthoParams(float near, float far, float left, float right, float bottom, float top)
	{
		type_ = PRT_ORTHOGRAPHIC;
		proj_mat_ = MathLib::orthoLH(near, far, left, right, bottom, top);
	}


	ProjectionType Camera::GetProjectionType()
	{
		return type_;
	}

}