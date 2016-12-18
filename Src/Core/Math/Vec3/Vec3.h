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
    Vec3(float x, float y, float z);
    Vec3(float (&array)[3]);
    Vec3(const Vec3 &other);
    Vec3 &operator=(const Vec3 &other);
    ~Vec3() = default;
 
public:
    Vec3 operator+(const Vec3 &vector) const;
    Vec3 &operator+=(const Vec3 &vector);
    Vec3 operator-(const Vec3 &vector) const;
    Vec3 &operator-=(const Vec3 &vector);
    Vec3 operator*(float scalar) const;
    Vec3 &operator*=(float scalar);
    Vec3 operator/(float scalar) const;
    Vec3 &operator/=(float scalar);
 
public:
    float mod() const;      // Module
    float rmod() const;     // Module's reciprocal
    Vec3 &nor();      // Normalization
 
public:
    float dot(const Vec3 &vector) const;        // Dot Product
    Vec3 cro(const Vec3 &vector) const;         // Cross Product
    Vec3 pro(const Vec3 &vector) const;		  // Projection

public:
    void set(float (&array)[3]);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
 
public:
    float x() const;
    float y() const;
    float z() const;
 
private:
    float mX;
    float mY;
    float mZ;
};
 
#endif // RALFLIGHT_SRC_CORE_MATH_VEC3_H