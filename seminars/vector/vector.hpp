#ifndef VECTOR_H// if not defined
#define VECTOR_H
#include <iostream>

namespace notstd
{
const size_t initSize = 10;
template<typename T>
class vector
{
private:
    T* _begin;
    T* _end;
    size_t _cache_size;

public:
    vector()
    {
        _cache_size = initSize;
        _begin = new T[_cache_size];
        _end = _begin;// empty array
    };

    vector(std::initializer_list<T> il)
    {
        _cache_size = std::max({initSize, il.size()});// если больше 10 ставим сразу свой размер
        _begin = new T[_cache_size];
        _end = _begin;
        for (auto i = il.begin(); i < il.end(); i++)
        {// проходимся по il сразу
            this->push_back(*i);
        }
    };

    ~vector()
    {
        delete[] _begin;// delete на весь массив
    };

    size_t size() const
    {
        return _end - _begin;
    };

    void push_back(T elem)
    {
        if (this->size() == _cache_size - 1)
        {
            _cache_size += _cache_size;
            T* temp = new T[_cache_size];
            for (size_t i = 0; i < this->size(); i++)
            {
                temp[i] = _begin[i];
            };
            _end = &temp[this->size()];
            delete[] _begin;
            _begin = temp;
            push_back(elem);
        }
        else
        {
            *_end = elem;
            _end++;
        }
    }
    T& operator[](size_t i)//&&&&🤡🤡
    {
        if (i > this->size())
        {
            throw std::out_of_range("invalid index");
        }
        return _begin[i];
    }
};
};// namespace notstd

#endif
