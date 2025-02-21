#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
    virtual void append(T value) = 0;
    virtual void insert(T value, unsigned int ind) = 0;
    virtual void remove(unsigned int ind) = 0;
    virtual void print(void) = 0;
    virtual ~Vector() {}
};

template <typename T>
class StdVector: public Vector<T>
{
private:
    T* v;
    unsigned int size;
    unsigned int actualSize;
    void memcpy(T* dst, T* src, unsigned int sz)
    {
        for (unsigned int ind = 0; ind < sz; ind++)
        {
            dst[ind] = src[ind];
        }
    }
public:
    StdVector(): v(new T[0]), size(0), actualSize(0)
    {

    }
    StdVector(unsigned int iniSize): v(new T[0]), size(0), actualSize(iniSize)
    {

    }
    virtual void append(T value) override 
    {
        if (actualSize > size)
        {
            v[size++] = value;
        }
        else
        {
            T* other = new T[size + 1];
            memcpy(other, v, size);
            other[size] = value;
            size++;
            delete[] v;
            v = other;
        }
    }
    virtual void insert(T value, unsigned int ind) override {}
    virtual void remove(unsigned int ind) override {}
    virtual void print(void) override
    {
        cout << "[ ";
        for (unsigned int ind = 0; ind < size; ind++)
        {
            cout << v[ind] << " ";
        }
        cout << "]" << endl;
    }
    virtual ~StdVector()
    {
        delete[] v;
    }
};

#endif