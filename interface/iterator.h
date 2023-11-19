#pragma once

#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <iterator>

template<class T>
class Iterator
{
private:
    std::vector<std::vector<T>>::iterator itr;

public:
    explicit Iterator(std::vector<std::vector<T>>::iterator itr) : itr(itr) {}

    std::vector<T>& operator*() const;
    Iterator<T> operator++();
    bool operator!=(const Iterator<T> &other) const;
};

#endif