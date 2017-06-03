#ifndef _COOLGE_MATRIX
#define _COOLGE_MATRIX

#pragma once

#include "Vector.hpp"

namespace CoolGE
{
	template <typename T>
	class Matrix4_T
	{
	public:
		Matrix4_T()
		{

		}

		Matrix4_T(Matrix4_T const & rhs)
		{
			for (size_t i = 0; i < row_num; i++)
			{
				m[i] = rhs.m[i];
			}
		}
		Matrix4_T(Matrix4_T const && rhs)
		{
			return std::move(rhs);
		}

		Matrix4_T(T f11, T f12, T f13, T f14,
			T f21, T f22, T f23, T f24,
			T f31, T f32, T f33, T f34,
			T f41, T f42, T f43, T f44)
		{
			m[0][0] = f11;
			m[0][1] = f12;
			m[0][2] = f13;
			m[0][3] = f14;
			m[1][0] = f21;
			m[1][1] = f22;
			m[1][2] = f23;
			m[1][3] = f24;
			m[2][0] = f31;
			m[2][1] = f32;
			m[2][2] = f33;
			m[2][3] = f34;
			m[3][0] = f41;
			m[3][1] = f42;
			m[3][2] = f43;
			m[3][3] = f44;
		}
		T& operator()(size_t row, size_t col)
		{
			return m[row][col];
		}
		Matrix4_T const& Identity()
		{
			static Matrix4_T const out(
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			);
			return out;
		}

		Vector_T<T, 4> const & Row(size_t index)
		{
			return m[index];
		}
		Vector_T<T, 4> const Col(size_t index)
		{
			Vector_T<T, 4> ret;
			for (size_t i = 0; i < 3; i++)
			{
				ret[i] = m[i][index];
			}
			return ret;
		}
		Matrix4_T& operator *= (Matrix4_T const & rhs)
		{
			//*this = MathLib::mul(*this, rhs);
			return *this;

		}
		//Matrix4_T& operator+=(Matrix4_T const & rhs);
		//Matrix4_T& operator-=(Matrix4_T const & rhs);
		//Matrix4_T& operator*=(Matrix4_T const & rhs);
		//Matrix4_T& operator*=(T rhs);
		//Matrix4_T& operator/=(T rhs);
		Matrix4_T& operator=(Matrix4_T const & rhs) = default;
		Matrix4_T& operator=(Matrix4_T&& rhs) = default;
		//Matrix4_T const operator+() const;
		//Matrix4_T const operator-() const;
		//bool operator==(Matrix4_T const & rhs) const;

		Matrix4_T getTranspose()
		{
			return Matrix4_T(m[0][0], m[1][0], m[2][0], m[3][0],
				m[0][1], m[1][1], m[2][1], m[3][1],
				m[0][2], m[1][2], m[2][2], m[3][2],
				m[0][3], m[1][3], m[2][3], m[3][3])
		}
		enum { row_num = 4, col_num = 4 };
	private:
		Vector_T<Vector_T<T, col_num>, row_num>  m;
	};
}





#endif