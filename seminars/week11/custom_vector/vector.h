// header guards, нужны для того чтобы не было ошибок с переопределениями
// если не объявлен то заинклюдь, если нет то запусти
#ifndef VECTOR_H//if not defined
#define VECTOR_H
#include <iostream>

namespace merin
{
template<typename T>//шаблон типа Т
class vector
{
public:
    vector();
    size_t size();
    T& operator[](size_t);
    ~vector();
    void push_back(T);

private:
    T* _arr;
    T* _end;
    size_t _size;
};

const size_t initSize = 10;
};// namespace merin
#endif
