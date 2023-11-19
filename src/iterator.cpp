#include "iterator.h"
#include <vector>
#include <iterator>

template<class T>
std::vector<T>& Iterator<T>::operator*() const
{
    return *itr;
}

template<class T>
Iterator<T> Iterator<T>::operator++()
{
    ++itr;
    return *this;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const
{
    return this->itr != other.itr;
}
