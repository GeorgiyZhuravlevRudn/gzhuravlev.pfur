#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
class Matrix {
private:
    unsigned m_rowSize;
    unsigned m_colSize;
    double** m_matrix;
    void alloc();
public:
    Matrix(unsigned rowSize, unsigned colSize);
    Matrix(const Matrix &);
    Matrix(const char*);
    Matrix();
    ~Matrix();

    // Matrix Operations
    Matrix &operator +=(const Matrix &);;
    Matrix &operator -=(const Matrix &);
    Matrix &operator *=(const Matrix &);
    Matrix &operator=(const Matrix &);
    Matrix transpose();


    // Scalar Operations

    Matrix &operator+=(double);
    Matrix &operator-=(double);
    Matrix &operator*=(double);
    Matrix &operator/=(double);

    // Other Methods
    double& operator()(const unsigned &, const unsigned &);
    void print();
    void SetParam();
    void Set_element(const unsigned , const unsigned, const double );
    double& Get_element(const unsigned , const unsigned);
    void Set_rows(unsigned);
    void Set_cols(unsigned);
    unsigned getRows() const;
    unsigned getCols() const;
    void setSize(unsigned,unsigned);


    // Deflation
    Matrix deflation(Matrix &, double&);
};
Matrix operator +(const Matrix&,const Matrix&);
Matrix operator -(const Matrix&,const Matrix&);
Matrix operator *(const Matrix&,const Matrix&);
Matrix operator+(const Matrix&,double);
Matrix operator-(const Matrix&,double);
Matrix operator*(const Matrix&,double);
Matrix operator/(const Matrix&,double);


#endif
