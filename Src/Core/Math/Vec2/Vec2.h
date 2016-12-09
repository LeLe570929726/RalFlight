// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC2_H
#define RALFLIGHT_SRC_CORE_MATH_VEC2_H

#include <intrin.h>

class Vec2 {
public:
    explicit Vec2(float x, float y);
    explicit Vec2(const vec2 &other);
    Vec3 &operator=(const vec2 &other);
    ~Vec2() = default;

public:
    Vec2 operator+(const Vec2 &vector);
    Vec2 &operator+=(const Vec2 &vector);
    Vec2 operator-(const Vec2 &vector);
    Vec2 &operator-=(const Vec2 &vector);
    Vec2 operator*(float scalar);
    Vec2 &operator*=(float scalar);
    Vec2 operator/(float scalar);
    Vec2 &operator/=(float scalar);

public:
    float mod();      // Module
    float rmod();     // Module's reciprocal
    Vec2 &nor();        // Normalization

public:
    static float dot(const Vec2 &vectorA, const Vec2 &vectorB);        // Dot Product

public:
    float x();
    float y();

private:
    float mX;
    float mY;
};

#endif        // RALFLIGHT_SRC_CORE_MATH_VEC2_H