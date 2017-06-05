#ifndef _COOLGE_MATH
#define _COOLGE_MATH


#pragma once
namespace CoolGE
{
	float const PI = 3.141592f;
	float const PI2 = 6.283185f;
	float const PIHALF = 1.570796f;
	float const DEG90 = 1.570796f;
	namespace MathLib
	{
		// 内积
		template <typename T,int N>
		T dot(Vector_T<T, N> const & lhs, Vector_T<T, N> const & rhs)
		{
			T ret = 0;
			for (auto i = 0; i < N; i++)
			{
				ret += lhs[i] * rhs[i];
			}
			return ret;
		}

		// 长度
		template <typename T,int N>
		T length(Vector_T<T, N> const & lhs)
		{
			return sqrt(dot(lhs, lhs));
		}

		// 单位化
		template <typename T,int N>
		Vector_T<T, N> normalize(Vector_T<T, N> const & lhs)
		{
			return lhs * (1 / length(lhs));
		}

		// 外积
		template <typename T>
		T cross(Vector_T<T, 2> const & lhs, Vector_T<T, 2> const & rhs)
		{
			return lhs.x() * rhs.y() - lhs.y() * rhs.x();
		}

		//外积 （x1,y1,z1）×（x2,y2,z2）=(y1z2-y2z1,z1x2-z2x1,x1y2-x2y1）
		template <typename T>
		Vector_T<T, 3> cross(Vector_T<T, 3> const & lhs, Vector_T<T, 3> const & rhs)
		{
			return Vector_T<T, 3>(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
				lhs.z() * rhs.x() - lhs.x() * rhs.z(),
				lhs.x() * rhs.y() - lhs.y() * rhs.x());
		}

		//4*4矩阵相乘
		template <typename T>
		Matrix4_T<T> mul(Matrix4_T<T> const & lhs, Matrix4_T<T> const & rhs)
		{
			Matrix4_T<T> const tmp(transpose(rhs));

			return Matrix4_T<T>(
				lhs(0, 0) * tmp(0, 0) + lhs(0, 1) * tmp(0, 1) + lhs(0, 2) * tmp(0, 2) + lhs(0, 3) * tmp(0, 3),
				lhs(0, 0) * tmp(1, 0) + lhs(0, 1) * tmp(1, 1) + lhs(0, 2) * tmp(1, 2) + lhs(0, 3) * tmp(1, 3),
				lhs(0, 0) * tmp(2, 0) + lhs(0, 1) * tmp(2, 1) + lhs(0, 2) * tmp(2, 2) + lhs(0, 3) * tmp(2, 3),
				lhs(0, 0) * tmp(3, 0) + lhs(0, 1) * tmp(3, 1) + lhs(0, 2) * tmp(3, 2) + lhs(0, 3) * tmp(3, 3),

				lhs(1, 0) * tmp(0, 0) + lhs(1, 1) * tmp(0, 1) + lhs(1, 2) * tmp(0, 2) + lhs(1, 3) * tmp(0, 3),
				lhs(1, 0) * tmp(1, 0) + lhs(1, 1) * tmp(1, 1) + lhs(1, 2) * tmp(1, 2) + lhs(1, 3) * tmp(1, 3),
				lhs(1, 0) * tmp(2, 0) + lhs(1, 1) * tmp(2, 1) + lhs(1, 2) * tmp(2, 2) + lhs(1, 3) * tmp(2, 3),
				lhs(1, 0) * tmp(3, 0) + lhs(1, 1) * tmp(3, 1) + lhs(1, 2) * tmp(3, 2) + lhs(1, 3) * tmp(3, 3),

				lhs(2, 0) * tmp(0, 0) + lhs(2, 1) * tmp(0, 1) + lhs(2, 2) * tmp(0, 2) + lhs(2, 3) * tmp(0, 3),
				lhs(2, 0) * tmp(1, 0) + lhs(2, 1) * tmp(1, 1) + lhs(2, 2) * tmp(1, 2) + lhs(2, 3) * tmp(1, 3),
				lhs(2, 0) * tmp(2, 0) + lhs(2, 1) * tmp(2, 1) + lhs(2, 2) * tmp(2, 2) + lhs(2, 3) * tmp(2, 3),
				lhs(2, 0) * tmp(3, 0) + lhs(2, 1) * tmp(3, 1) + lhs(2, 2) * tmp(3, 2) + lhs(2, 3) * tmp(3, 3),

				lhs(3, 0) * tmp(0, 0) + lhs(3, 1) * tmp(0, 1) + lhs(3, 2) * tmp(0, 2) + lhs(3, 3) * tmp(0, 3),
				lhs(3, 0) * tmp(1, 0) + lhs(3, 1) * tmp(1, 1) + lhs(3, 2) * tmp(1, 2) + lhs(3, 3) * tmp(1, 3),
				lhs(3, 0) * tmp(2, 0) + lhs(3, 1) * tmp(2, 1) + lhs(3, 2) * tmp(2, 2) + lhs(3, 3) * tmp(2, 3),
				lhs(3, 0) * tmp(3, 0) + lhs(3, 1) * tmp(3, 1) + lhs(3, 2) * tmp(3, 2) + lhs(3, 3) * tmp(3, 3));

		}

		// 行列式
		template <typename T>
		T determinant(Matrix4_T<T> const & rhs)
		{
			T const _3142_3241(rhs(2, 0) * rhs(3, 1) - rhs(2, 1) * rhs(3, 0));
			T const _3143_3341(rhs(2, 0) * rhs(3, 2) - rhs(2, 2) * rhs(3, 0));
			T const _3144_3441(rhs(2, 0) * rhs(3, 3) - rhs(2, 3) * rhs(3, 0));
			T const _3243_3342(rhs(2, 1) * rhs(3, 2) - rhs(2, 2) * rhs(3, 1));
			T const _3244_3442(rhs(2, 1) * rhs(3, 3) - rhs(2, 3) * rhs(3, 1));
			T const _3344_3443(rhs(2, 2) * rhs(3, 3) - rhs(2, 3) * rhs(3, 2));

			return rhs(0, 0) * (rhs(1, 1) * _3344_3443 - rhs(1, 2) * _3244_3442 + rhs(1, 3) * _3243_3342)
				- rhs(0, 1) * (rhs(1, 0) * _3344_3443 - rhs(1, 2) * _3144_3441 + rhs(1, 3) * _3143_3341)
				+ rhs(0, 2) * (rhs(1, 0) * _3244_3442 - rhs(1, 1) * _3144_3441 + rhs(1, 3) * _3142_3241)
				- rhs(0, 3) * (rhs(1, 0) * _3243_3342 - rhs(1, 1) * _3143_3341 + rhs(1, 2) * _3142_3241);
		}

		// 逆矩阵，行列式为0 时返回原矩阵
		template <typename T>
		Matrix4_T<T> inverse(Matrix4_T<T> const & rhs)
		{
			T const _2132_2231(rhs(1, 0) * rhs(2, 1) - rhs(1, 1) * rhs(2, 0));
			T const _2133_2331(rhs(1, 0) * rhs(2, 2) - rhs(1, 2) * rhs(2, 0));
			T const _2134_2431(rhs(1, 0) * rhs(2, 3) - rhs(1, 3) * rhs(2, 0));
			T const _2142_2241(rhs(1, 0) * rhs(3, 1) - rhs(1, 1) * rhs(3, 0));
			T const _2143_2341(rhs(1, 0) * rhs(3, 2) - rhs(1, 2) * rhs(3, 0));
			T const _2144_2441(rhs(1, 0) * rhs(3, 3) - rhs(1, 3) * rhs(3, 0));
			T const _2233_2332(rhs(1, 1) * rhs(2, 2) - rhs(1, 2) * rhs(2, 1));
			T const _2234_2432(rhs(1, 1) * rhs(2, 3) - rhs(1, 3) * rhs(2, 1));
			T const _2243_2342(rhs(1, 1) * rhs(3, 2) - rhs(1, 2) * rhs(3, 1));
			T const _2244_2442(rhs(1, 1) * rhs(3, 3) - rhs(1, 3) * rhs(3, 1));
			T const _2334_2433(rhs(1, 2) * rhs(2, 3) - rhs(1, 3) * rhs(2, 2));
			T const _2344_2443(rhs(1, 2) * rhs(3, 3) - rhs(1, 3) * rhs(3, 2));
			T const _3142_3241(rhs(2, 0) * rhs(3, 1) - rhs(2, 1) * rhs(3, 0));
			T const _3143_3341(rhs(2, 0) * rhs(3, 2) - rhs(2, 2) * rhs(3, 0));
			T const _3144_3441(rhs(2, 0) * rhs(3, 3) - rhs(2, 3) * rhs(3, 0));
			T const _3243_3342(rhs(2, 1) * rhs(3, 2) - rhs(2, 2) * rhs(3, 1));
			T const _3244_3442(rhs(2, 1) * rhs(3, 3) - rhs(2, 3) * rhs(3, 1));
			T const _3344_3443(rhs(2, 2) * rhs(3, 3) - rhs(2, 3) * rhs(3, 2));

			T const det(determinant(rhs));
			if (equal<T>(det, 0))
			{
				return rhs;
			}
			else
			{
				T invDet(T(1) / det);

				return Matrix4_T<T>(
					+invDet * (rhs(1, 1) * _3344_3443 - rhs(1, 2) * _3244_3442 + rhs(1, 3) * _3243_3342),
					-invDet * (rhs(0, 1) * _3344_3443 - rhs(0, 2) * _3244_3442 + rhs(0, 3) * _3243_3342),
					+invDet * (rhs(0, 1) * _2344_2443 - rhs(0, 2) * _2244_2442 + rhs(0, 3) * _2243_2342),
					-invDet * (rhs(0, 1) * _2334_2433 - rhs(0, 2) * _2234_2432 + rhs(0, 3) * _2233_2332),

					-invDet * (rhs(1, 0) * _3344_3443 - rhs(1, 2) * _3144_3441 + rhs(1, 3) * _3143_3341),
					+invDet * (rhs(0, 0) * _3344_3443 - rhs(0, 2) * _3144_3441 + rhs(0, 3) * _3143_3341),
					-invDet * (rhs(0, 0) * _2344_2443 - rhs(0, 2) * _2144_2441 + rhs(0, 3) * _2143_2341),
					+invDet * (rhs(0, 0) * _2334_2433 - rhs(0, 2) * _2134_2431 + rhs(0, 3) * _2133_2331),

					+invDet * (rhs(1, 0) * _3244_3442 - rhs(1, 1) * _3144_3441 + rhs(1, 3) * _3142_3241),
					-invDet * (rhs(0, 0) * _3244_3442 - rhs(0, 1) * _3144_3441 + rhs(0, 3) * _3142_3241),
					+invDet * (rhs(0, 0) * _2244_2442 - rhs(0, 1) * _2144_2441 + rhs(0, 3) * _2142_2241),
					-invDet * (rhs(0, 0) * _2234_2432 - rhs(0, 1) * _2134_2431 + rhs(0, 3) * _2132_2231),

					-invDet * (rhs(1, 0) * _3243_3342 - rhs(1, 1) * _3143_3341 + rhs(1, 2) * _3142_3241),
					+invDet * (rhs(0, 0) * _3243_3342 - rhs(0, 1) * _3143_3341 + rhs(0, 2) * _3142_3241),
					-invDet * (rhs(0, 0) * _2243_2342 - rhs(0, 1) * _2143_2341 + rhs(0, 2) * _2142_2241),
					+invDet * (rhs(0, 0) * _2233_2332 - rhs(0, 1) * _2133_2331 + rhs(0, 2) * _2132_2231));
			}
		}

		//透视投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> perspectiveRH(T near, T far, T left, T right, T bottom, T top)
		{
			return Matrix4_T<T>(2 * near / (right - left), 0, 0, 0,
				0, 2 * near / (top - bottom), 0, 0,
				(right + left) / (right - left), (top + bottom) / (top - bottom), (-far - near) / (far - near), -1,
				0, 0, -2 * near*far / (far - near), 0);

		}

		//透视投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> perspectiveRH(T fovy, T aspect, T zNear, T zFar)
		{
			T xmin, xmax, ymin, ymax;

			ymax = zNear * tan(fovy * 0.5);
			ymin = -ymax;
			xmin = ymin * aspect;
			xmax = -xmin;

			return perspectiveRH(zNear, zFar, xmin, xmax, ymin, ymax);
		}

		//透视投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> perspectiveLH(T near, T far, T left, T right, T bottom, T top)
		{
			return Matrix4_T<T>(2 * near / (right - left), 0, 0, 0,
				0, 2 * near / (top - bottom), 0, 0,
				-(right + left) / (right - left), -(top + bottom) / (top - bottom), (far + near) / (far - near), 1,
				0, 0, -2 * near*far / (far - near), 0);
		}
		//透视投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> perspectiveLH(T fovy, T aspect, T zNear, T zFar)
		{
			T xmin, xmax, ymin, ymax;

			ymax = zNear * tan(fovy * (T)0.5);
			ymin = -ymax;
			xmin = ymin * aspect;
			xmax = -xmin;

			return perspectiveRH(zNear, zFar, xmin, xmax, ymin, ymax);
		}

		// 正射投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> orthoRH(T near, T far, T left, T right, T bottom, T top)
		{
			return Matrix4_T<T>(2 / (right - left), 0, 0, 0,
				0, 2 / (top - bottom), 0, 0,
				0, 0, 2 / (far - near), 0,
				-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1);
		}

		// 正射投影矩阵，从观察空间变换至奇次裁剪空间 z[-1,1]
		template <typename T>
		Matrix4_T<T> orthoLH(T near, T far, T left, T right, T bottom, T top)
		{
			return Matrix4_T<T>(2 / (right - left), 0, 0, 0,
				0, 2 / (top - bottom), 0, 0,
				0, 0, -2 / (far - near), 0,
				-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1);
		}



		// 观察至世界矩阵
		template <typename T>
		Matrix4_T<T> lookatRH(Vector_T<T,3> const & vEye, Vector_T<T, 3> const &  vAt, Vector_T<T, 3> const &  vUp)
		{
			Vector_T<T, 3> zAxis(normalize(vEye - vAt));
			Vector_T<T, 3> xAxis(normalize(cross(vUp, zAxis)));
			Vector_T<T, 3> yAxis(cross(zAxis, xAxis));
			// Vector_T<T, 3> yAxis(normalize(vUp)); //个人理解，待测试

			return Matrix4_T<T>(
				xAxis.x(), yAxis.x(), zAxis.x(), 0,
				xAxis.y(), yAxis.y(), zAxis.y(), 0,
				xAxis.z(), yAxis.z(), zAxis.z(), 0,
				-dot(xAxis, vEye), -dot(yAxis, vEye), -dot(zAxis, vEye), 1);		
		}

		template <typename T>
		Matrix4_T<T> lookatLH(Vector_T<T, 3> const &  vEye, Vector_T<T, 3> const &  vAt, Vector_T<T, 3> const &  vUp)
		{
			Vector_T<T, 3> zAxis(normalize(vAt - vEye));
			Vector_T<T, 3> xAxis(normalize(cross(vUp, zAxis)));
			Vector_T<T, 3> yAxis(cross(zAxis, xAxis));
			// Vector_T<T, 3> yAxis(normalize(vUp)); //个人理解，待测试

			return Matrix4_T<T>(
				xAxis.x(), yAxis.x(), zAxis.x(), 0,
				xAxis.y(), yAxis.y(), zAxis.y(), 0,
				xAxis.z(), yAxis.z(), zAxis.z(), 0,
				-dot(xAxis, vEye), -dot(yAxis, vEye), -dot(zAxis, vEye), 1);
		}






	}
}

#include "Matrix.hpp"

#endif