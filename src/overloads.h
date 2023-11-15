/*This header file provides basic arithmetic operator overloads for the vector class*/

#pragma once

#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <vector>
#include <stdexcept>

template<class T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b)
{
    if (a.size() != b.size())
        throw std::invalid_argument("Vector sizes do not match");

    std::vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
        result[i] = a[i] + b[i];
    return result;
}

template<class T>
std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b)
{
    if (a.size() != b.size())
        throw std::invalid_argument("Vector sizes do not match");

    std::vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
        result[i] = a[i] - b[i];
    return result;
}

template<class T>
std::vector<T> operator*(const std::vector<T> &a, T k)
{
    std::vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
        result[i] = a[i] * k;
    return result;
}

template<class T>
std::vector<T> operator/(const std::vector<T> &a, T k)
{
    std::vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
        result[i] = a[i] / k;
    return result;
}

#endif