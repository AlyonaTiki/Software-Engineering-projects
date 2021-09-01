// home project#1
// class template SquareMatrix that implements a square matrix of elements of a specified type.

#pragma once
#include <iostream>
using namespace std;

template<typename T>
class SquareMatrix
{
private:
    T** _dPtr; //double pointer to array of elements
    size_t _size; //size of a matrix, number of columss/rows in matrix

public:
    SquareMatrix(); //default constructor

    // Big Five
    ~SquareMatrix(); //destructor
    SquareMatrix(const SquareMatrix& trg); //copy constructor
    SquareMatrix(SquareMatrix&& trg); //move constructor
    SquareMatrix& operator=(const SquareMatrix& rhs); //copy assignment
    SquareMatrix& operator=(SquareMatrix&& rhs); //move assignment


    void resize(size_t new_size); //resize matrix to a given size
    bool operator==(SquareMatrix); //check if matrices are equal
    SquareMatrix& operator+(const SquareMatrix& rhs); //addition of two square matrices of the same size
    T& at(int row,int column); //get content at specific row and col
    size_t size() const; //get size of a matrix
};

template<typename T>
SquareMatrix<T>::SquareMatrix() : _dPtr(nullptr), _size(0)
{ }

template<typename T>
SquareMatrix<T>::~SquareMatrix()  //destructor, to free memory
{
    if(_dPtr != nullptr)
    {
        for(int i = 0; i < _size; i++) {
            delete[] _dPtr[i]; // free memory
        }
        delete [] _dPtr;
    }
}

template<typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix &trg) //copy constructor
{
    _size = trg._size;
    if(trg._dPtr == nullptr)
    {
        _dPtr = nullptr;
        return;
    }
    _dPtr = new T * [_size]; // allocate memory
    for(int i = 0; i < _size; i++)
        _dPtr[i] = new T [_size];
    for(int i = 0; i < _size; i++)
        for(int j = 0; j < _size; j++)
            _dPtr[i][j] = trg._dPtr[i][j]; //copy every element
}

template<typename T>
SquareMatrix<T>::SquareMatrix(SquareMatrix &&trg)  //move constructor
{
    _dPtr = trg._dPtr; //assign data members from the source object to the object that is being constructed
    _size = trg._size;
    trg._dPtr = nullptr; //assign to default value
}

template<typename T>
SquareMatrix<T> &SquareMatrix<T>::operator=(const SquareMatrix &rhs) //copy assignment
{
    if(_size != rhs._size)
    {
        for(int i = 0; i < _size; i++)
            delete [] _dPtr[i]; // free memory in left obj(destination)
        delete [] _dPtr;

        _size = rhs._size; //get size of the new matrix
        _dPtr = new T * [_size]; // allocate memory
        for(int i = 0; i < _size; i++)
            _dPtr[i] = new T [_size];
    }
    for(int i = 0; i < _size; i++)
        for(int j = 0; j < _size; j++)
            _dPtr[i][j] = rhs._dPtr[i][j]; // copy from right(the source) obj to left(destination)
    return *this;
}

template<typename T>
SquareMatrix<T> &SquareMatrix<T>::operator=(SquareMatrix &&rhs) //move assignment
{

//    if (_dPtr != nullptr) //// mistake all move assignment start with if( this==&rhs )
//    {
//
//    }
    if( this==&rhs ){
        delete[] _dPtr; //free memory
    }
    _dPtr = rhs._dPtr; //assign data members from the source object to the object that is being constructed
    _size = rhs._size;
    rhs._dPtr = nullptr; //assign to default value

    return *this;
}


template<typename T>
void SquareMatrix<T>::resize(size_t new_size) //resize matrix to a given size
{
    if (new_size > 0) //if given size is valid
    {
        for (int i = 0; i < _size; i++)
            delete[] _dPtr[i]; //destroys all previous content of the matrix
        delete[] _dPtr; //releases all memory

        _size = new_size; //get size of the new matrix
        _dPtr = new T *[_size]; // allocate memory
        for (int i = 0; i < _size; i++)
            _dPtr[i] = new T[_size];
    }else
    {
        throw out_of_range("resize(new_size): Size of the matrix have to be greater than 0");
    }
}


template<typename T>
bool SquareMatrix<T>::operator==(SquareMatrix MatrixB ) //check if matrices are equal
{
    if(MatrixB._size == _size) //check if sizes are equal
    {
        for(int i = 0; i < _size; i++)
            for(int j = 0; j < _size; j++)
                if (_dPtr[i][j] == MatrixB._dPtr[i][j]) //check content of matrices
                {
                    return true;
                }
    }
    return false;
}

template<typename T>
T& SquareMatrix<T>::at(int row, int column) //return content at specific row and col
{
    if ((row >= 0 && row < _size) && (column >=0 && column < _size))
    {
        return _dPtr[row][column];
    } else
    {
        throw out_of_range("at(row,column): Position is out of the matrix range");
    }
}

template<typename T>
SquareMatrix<T> &SquareMatrix<T>::operator+(const SquareMatrix &rhs) //addition of two square matrices
{
    for(int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _dPtr[i][j] = (_dPtr[i][j] + rhs._dPtr[i][j]); //sum of given matrices
        }
    }
    return *this;
}

template<typename T>
size_t SquareMatrix<T>::size() const //returns the current size of the matrix
{
    return _size;
}


