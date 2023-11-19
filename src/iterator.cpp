#include <vector>
#include <iterator>

#include "iterator.h"

template<class T>
inline std::vector<T>& Iterator<T>::operator*() const
{
    return *itr;
}

template<class T>
inline Iterator<T> Iterator<T>::operator++()
{
    ++itr;
    return *this;
}

template<class T>
inline bool Iterator<T>::operator!=(const Iterator<T> &other) const
{
    return this->itr != other.itr;
}
