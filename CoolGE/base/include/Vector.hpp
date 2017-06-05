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
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const * const_pointer;

		//template<typename U, int M>
		//friend class Vector_T;
	public:
		Vector_T()
		{
		}
		enum {elem_num = N};
	public:
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
	public:
		T& x()
		{
			static_assert(elem_num >= 1,"must be 1d vector");
			return m[0];
		}
		T& y()
		{
			static_assert(elem_num >= 2, "must be 2d vector");
			return m[1];
		}
		T& z()
		{
			static_assert(elem_num >= 3, "must be 3d vector");
			return m[2];
		}
		T& w()
		{
			static_assert(elem_num >= 4, "must be 4d vector");
			return m[3];
		}
		const T& x() const
		{
			static_assert(elem_num >= 1, "must be 1d vector");
			return m[0];
		}
		const T& y() const
		{
			static_assert(elem_num >= 2, "must be 2d vector");
			return m[1];
		}
		const T& z() const
		{
			static_assert(elem_num >= 3, "must be 3d vector");
			return m[2];
		}
		const T& w() const
		{
			static_assert(elem_num >= 4, "must be 4d vector");
			return m[3];
		}

		template <typename U, int N>
		Vector_T operator+=(Vector_T<U, N> const &rhs)
		{
			for (int i = 0; i < N; i++)
			{
				m[i] += rhs[i];
			}
			return *this;
		}
		template <typename U, int N>
		Vector_T operator-= (Vector_T<U, N> const &rhs)
		{
			for (int i = 0; i < N; i++)
			{
				m[i] -= rhs[i];
			}
			return *this;
		}
		template <typename U, int N>
		Vector_T operator*= (Vector_T<U, N> const &rhs)
		{
			for (int i = 0; i < N; i++)
			{
				m[i] *= rhs[i];
			}
			return *this;
		}
		template <typename U>
		Vector_T operator*= (U const &s)
		{
			for (int i = 0; i < N; i++)
			{
				m[i] *= s;
			}
			return *this;
		}

		T& operator[](size_t index)
		{
			return m[index];
		}

		const T& operator[](size_t index) const
		{
			return m[index];
		}

		Vector_T& operator=(Vector_T const &rhs)
		{
			if (this != &rhs)
			{
				m = rhs.m;
			}
			return *this;
		}

		Vector_T& operator=(Vector_T const &&rhs)
		{
			m = std::move(rhs.m);
			return *this;
		}

		Vector_T operator+(Vector_T const &rhs) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i] + rhs.m[i];
			}
			return ret;
		}		
		Vector_T operator-(Vector_T const &rhs) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i] - rhs[i];
			}
			return ret;
		}
		Vector_T operator*(Vector_T const &rhs) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i] * rhs.m[i];
			}
			return ret;
		}
		Vector_T operator/(Vector_T const &rhs) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i]/rhs.m[i];
			}
			return ret;
		}
		Vector_T operator*(T const &s) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i] * s;
			}
			return ret;
		}
		Vector_T operator/(T const &ss) const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = m[i] / s;
			}
			return ret;
		}
		Vector_T& operator+() const
		{
			return *this;
		}
		Vector_T operator-() const
		{
			Vector_T ret;
			for (int i = 0; i < N; i++)
			{
				ret[i] = -m[i];
			}

			return ret;
		}

		
	private:
		std::array<T,N> m;
	};
}
#endif