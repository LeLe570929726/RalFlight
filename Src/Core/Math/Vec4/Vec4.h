// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC4_H
#define RALFLIGHT_SRC_CORE_MATH_VEC4_H
 
#include <intrin.h>
 
class Vec4 {
public:
    Vec4(float x, float y, float z, float w);
    Vec4(const Vec4 &other);
    Vec4 &operator=(const Vec4 &other);
    ~Vec4() = default;
 
public:
    Vec4 operator+(const Vec4 &vector);
    Vec4 &operator+=(const Vec4 &vector);
    Vec4 operator-(const Vec4 &vector);
    Vec4 &operator-=(const Vec4 &vector);
    Vec4 operator*(float scalar);
    Vec4 &operator*=(float scalar);
    Vec4 operator/(float scalar);
    Vec4 &operator/=(float scalar);
 
public:
    float mod();      // Module
    float rmod();     // Module's reciprocal
    Vec4 &nor();      // Normalization
 
public:
    float dot(const Vec4 &vector);        // Dot Product
    Vec4 pro(const Vec4 &vector);		  // Projection
 
public:
    float x();
    float y();
    float z();
    float w();
 
private:
    float mX;
    float mY;
    float mZ;
    float mW;
};
 
#endif      // RALFLIGHT_SRC_CORE_MATH_VEC4_H