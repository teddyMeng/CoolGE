#ifndef _COOLGE_VECTOR
#define _COOLGE_VECTOR

#pragma once
#include "array"

namespace CoolGE
{
	template<typename T, int N>
	class Vector_T
	{
	public:
		template<typename U, int M>
		friend class Vector_T;
		Vector_T()
		{
		}
		enum {elem_num = N};
	public:
		T x()
		{
			static_assert(elem_num >= 1,"must be 1d vector");
			return m[0];
		}
		T y()
		{
			static_assert(elem_num >= 2, "must be 2d vector");
			return m[1];
		}
		T z()
		{
			static_assert(elem_num >= 3, "must be 3d vector");
			return m[2];
		}
		T w()
		{
			static_assert(elem_num >= 4, "must be 4d vector");
			return m[3];
		}
		Vector_T(T const& x, T const& y)
		{
			static_assert(2 == elem_num, "must be 2d vector");
			m[0] = x;
			m[1] = y;
		}
		Vector_T(T const& x, T const& y, T const& z)
		{
			static_assert(3 == elem_num, "must be 3d vector");
			m[0] = x;
			m[1] = y;
			m[2] = z;
		}
		Vector_T(T const& x, T const& y, T const& z, T const& w)
		{
			static_assert(4 == elem_num, "must be 4d vector");
			m[0] = x;
			m[1] = y;
			m[2] = z;
			m[3] = w;
		}
		Vector_T(T const&& x, T const&& y)
		{
			static_assert(2 == elem_num, "must be 2d vector");
			m[0] = std::move(x);
			m[1] = std::move(y);
		}
		Vector_T(T const&& x, T const&& y, T const&& z)
		{
			static_assert(3 == elem_num, "must be 3d vector");
			m[0] = std::move(x);
			m[1] = std::move(y);
			m[2] = std::move(z);
		}
		Vector_T(T const&& x, T const&& y, T const&& z, T const&& w)
		{
			static_assert(4 == elem_num, "must be 4d vector");
			m[0] = std::move(x);
			m[1] = std::move(y);
			m[2] = std::move(z);
			m[3] = std::move(w);
		}
		Vector_T(Vector_T const& rhs)
		{
			for (int i = 0; i < elem_num; i++)
			{
				m[i] = rhs[i];
			}
		}
		Vector_T& operator[](size_t index)
		{
			return m[index];
		}
	private:
		std::array<T,N> m;
	};
}
#endif