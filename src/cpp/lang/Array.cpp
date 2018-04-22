#include "cpp/lang/Array.h"
#include <exception>
#include <stdexcept>

template class Array<boolean>;
template class Array<i32>;
template class Array<u32>;
template class Array<float>;
template class Array<double>;

template <class T>
Array<T>::Array() : length(_length)
{
    _length = 0;
};

template <class T>
Array<T>::Array(std::initializer_list<T> list) : length(_length)
{
    _length = 0;
    _value = new T[list.size()];
    for (const T e : list)
    {
        _value[_length++] = (e);
    }
}

/* set item in at index */
template <class T>
T Array<T>::operator [](i32 index) const
{
    if (index < 0 || index >= length)
    {
        throw std::runtime_error("java.lang.Exception: Index out of bound.");
    }
    return _value[index];
}

/* get item at index */
template <class T>
T & Array<T>::operator [](i32 index)
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("java.lang.Exception: Index out of bound.");
    }

    return _value[index];
}

template <class T>
T Array<T>::getElementAt(int index)
{
    return (*this)[index];
}

template <class T>
u32 Array<T>::push(T item)
{
    _length++;
    T* _value1 = new T[_length];
    _value1[_length - 1] = item;
    for (int i = 0; i < _length-1; i++)
    {
        _value1[i] = _value[i];
    }
    
    delete[] _value;
    _value = _value1;
    return _length;
}

template <class T>
T Array<T>::pop()
{
    T item = _value[_length - 1];
    T* _value1 = new T[_length - 1];
    _length--;
    for (int i = 0; i < _length - 1; i++)
    {
        _value1[i] = _value[i];
    }

    delete[] _value;
    _value = _value1;
    return item;
}

template <class T>
Array<T>::~Array()
{
    delete[] _value;
};