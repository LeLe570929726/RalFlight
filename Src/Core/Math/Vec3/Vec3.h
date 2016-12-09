// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC3_H
#define RALFLIGHT_SRC_CORE_MATH_VEC3_H

#include <intrin.h>

class Vec3 {
public:
    explicit Vec3(float x, float y, float z);
    explicit Vec3(const vec3 &other);
    Vec3 &operator=(const vec3 &other);
    ~Vec3() = default;

public:
    Vec3 operator+(const Vec3 &vector);
    Vec3 &operator+=(const Vec3 &vector);
    Vec3 operator-(const Vec3 &vector);
    Vec3 &operator-=(const Vec3 &vector);
    Vec3 operator*(float scalar);
    Vec3 &operator*=(float scalar);
    Vec3 operator/(float scalar);
    Vec3 &operator/=(float scalar);

public:
    float mod();      // Module
    float rmod();     // Module's reciprocal
    Vec3 &nor();        // Normalization

public:
    static float dot(const Vec3 &vectorA, const Vec3 &vectorB);        // Dot Product
    static Vec3 cro(const Vec3 &vectorA, const Vec3 &vectorB);        // Cross Product

public:
    float x();
    float y();
    float z();

private:
    float mX;
    float mY;
    float mZ;
};

#endif        // RALFLIGHT_SRC_CORE_MATH_VEC3_H