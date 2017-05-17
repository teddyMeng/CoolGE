#ifndef _COOLGE_TYPES
#define _COOLGE_TYPES

#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"

namespace CoolGE
{
	typedef Vector_T<float, 3> vec3f;
	typedef Vector_T<float, 4> vec4f;
	typedef Matrix3_T<float> matrix3f;
	typedef Matrix4_T<float> matrix4f;
}

#endif