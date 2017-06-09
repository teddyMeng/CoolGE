#ifndef _COOLGE_TYPES
#define _COOLGE_TYPES

#pragma once

#include "Vector.hpp"
#include "PreDeclare.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "EnumTypes.hpp"


namespace CoolGE
{
	typedef Vector_T<float, 3> Vec3f;
	typedef Vector_T<float, 4> Vec4f;
	typedef Matrix4_T<float> Matrix4f;
}

#endif