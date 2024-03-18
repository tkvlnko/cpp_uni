#include "vector.h"

namespace merin
{
template<typename T>//шаблон типа Т
vector<T>::vector()
{
    _arr = new T[initSize];
    _size = initSize;
    _end = _arr;
}

template<typename T>
vector<T>::~vector()
{
    delete[] _arr;
}

template<typename T>
size_t vector<T>::size()
{
    return _size;
}

template<typename T>
T& vector<T>::operator[](size_t i)
{
    return _arr[i];
}

template<typename T>
void vector<T>::push_back(T newEl)
{
    if (_end - _arr + 1 < _size)
    {
        _arr[_end++] = newEl;// end это следующий элемент после последнего заполненного
        _size += 1;
    }
    else
    {
        T* temp = new T[_size * 2];
        for (size_t i = 0; i < _size(); i++)
    }
}


};// namespace merin