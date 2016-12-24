// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Scalar.h"

template <>
float Scalar<float>::cos(float scalar) {
    return cos(scalar);
}

template <>
float Scalar<float>::sin(float scalar) {
    return sin(scalar);
}

template <>
float Scalar<float>::tan(float scalar) {
    return tan(scalar);
}

template <>
float Scalar<float>::acos(float scalar) {
    return acos(scalar);
}

template <>
float Scalar<float>::asin(float scalar) {
    return asin(scalar);
}

template <>
float Scalar<float>::atan(float scalar) {
    return atan(scalar);
}

template <>
float Scalar<float>::pow(float scalarBase, float scalarExp) {
    return pow(scalarBase, scalarExp);
}

template <>
float Scalar<float>::sqrt(float scalar) {
    return sqrt(scalar);
}

template <>
float Scalar<float>::log(float scalar) {
    return log(scalar);
}

template <>
double Scalar<double>::cos(double scalar) {
    return cos(scalar);
}

template <>
double Scalar<double>::sin(double scalar) {
    return sin(scalar);
}

template <>
double Scalar<double>::tan(double scalar) {
    return tan(scalar);
}

template <>
double Scalar<double>::acos(double scalar) {
    return acos(scalar);
}

template <>
double Scalar<double>::asin(double scalar) {
    return asin(scalar);
}

template <>
double Scalar<double>::atan(double scalar) {
    return atan(scalar);
}

template <>
double Scalar<double>::pow(double scalarBase, double scalarExp) {
    return pow(scalarBase, scalarExp);
}

template <>
double Scalar<double>::sqrt(double scalar) {
    return sqrt(scalar);
}

template <>
double Scalar<double>::log(double scalar) {
    return log(scalar);
}