#ifndef _COOLGE_MATRIX
#define _COOLGE_MATRIX

#pragma once

#include "Vector.hpp"

namespace CoolGE
{
	template <typename T>
	class Matrix3_T
	{
	public:
		Matrix3_T()
		{

		}

		Matrix3_T(Matrix3_T const & rhs)
		{
			for (size_t i = 0; i < row_num; i++)
			{
				m[i] = rhs.m[i];
			}
		}
		Matrix3_T(Matrix3_T const && rhs)
		{
			return std::move(rhs);
		}

		Matrix3_T(T f11, T f12, T f13,
			T f21, T f22, T f23,
			T f31, T f32, T f33)
		{
			m[0][0] = f11;
			m[0][1] = f12;
			m[0][2] = f13;
			m[1][0] = f21;
			m[1][1] = f22;
			m[1][2] = f23;
			m[2][0] = f31;
			m[2][1] = f32;
			m[2][2] = f33;
		}
		T& operator()(size_t row, size_t col)
		{
			return m[row][col];
		}
		//Matrix3_T& operator+=(Matrix3_T const & rhs);
		//Matrix3_T& operator-=(Matrix3_T const & rhs);
		//Matrix3_T& operator*=(Matrix3_T const & rhs);
		//Matrix3_T& operator*=(T rhs);
		//Matrix3_T& operator/=(T rhs);
		//Matrix3_T& operator=(Matrix3_T const & rhs);
		//Matrix3_T& operator=(Matrix3_T&& rhs);
		//Matrix3_T const operator+() const;
		//Matrix3_T const operator-() const;
		//bool operator==(Matrix3_T const & rhs) const;
		enum { row_num = 3, col_num =3 };
	private:
		Vector_T<Vector_T<T, col_num>, row_num>  m;
	};

	template <typename T>
	class Matrix4_T
	{
	public:
		Matrix4_T();
		Matrix4_T(Matrix4_T const & rhs);
		Matrix4_T(Matrix4_T const && rhs);
		Matrix4_T(T f11, T f12, T f13, T f14,
			T f21, T f22, T f23, T f24,
			T f31, T f32, T f33, T f34,
			T f41, T f42, T f43, T f44);

		T& operator()(size_t row, size_t col)
		{
			return m[row][col];
		}
		Matrix4_T& operator+=(Matrix4_T const & rhs);
		Matrix4_T& operator-=(Matrix4_T const & rhs);
		Matrix4_T& operator*=(Matrix4_T const & rhs);
		Matrix4_T& operator*=(T rhs);
		Matrix4_T& operator/=(T rhs);
		Matrix4_T& operator=(Matrix4_T const & rhs);
		Matrix4_T& operator=(Matrix4_T&& rhs);
		Matrix4_T const operator+() const;
		Matrix4_T const operator-() const;
		bool operator==(Matrix4_T const & rhs) const;
	private:
		T  m[4][4];
	};
}





#endif