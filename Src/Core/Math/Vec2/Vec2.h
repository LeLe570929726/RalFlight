// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC2_H
#define RALFLIGHT_SRC_CORE_MATH_VEC2_H
 
#include "../../Global/Macro/Macro.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Vec2 {
	public:
		Vec2(float x, float y);
		Vec2(float(&array)[2]);
		Vec2(const Vec2 &other);
		Vec2 &operator=(const Vec2 &other);
		~Vec2() = default;

	public:
		Vec2 operator+(const Vec2 &vector) const;
		Vec2 &operator+=(const Vec2 &vector);
		Vec2 operator-(const Vec2 &vector) const;
		Vec2 &operator-=(const Vec2 &vector);
		Vec2 operator*(float scalar) const;
		Vec2 &operator*=(float scalar);
		Vec2 operator/(float scalar) const;
		Vec2 &operator/=(float scalar);

	public:
		float mod() const;      // Module
		float rmod() const;     // Module's reciprocal
		Vec2 &nor();            // Normalization

	public:
		float dot(const Vec2 &vector) const;      // Dot Product
		Vec2 pro(const Vec2 &vector) const;		  // Projection

	public:
		void set(float(&array)[2]);
		void setX(float x);
		void setY(float y);

	public:
		float x() const;
		float y() const;

	private:
		float mX;
		float mY;
	};

}

#endif // RALFLIGHT_SRC_CORE_MATH_VEC2_H