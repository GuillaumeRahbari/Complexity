//
//  Matrix.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include "Matrix.h"


/*!
 *  The matrix is implemented as a std::vector of Vector's. Each Vector
 *  represents a line of the matrix. They have all the same size (which is the
 *  number of columns).
 *
 *  All Vector's are first created empty, then they are assigned to a
 *  temporary Vector (mv) with the correct initial values.
 *
 *  \param nl number of lines
 *  \param nc number of columns
 *  \param x the common value to initialize all components with
 *
 */
Matrix::Matrix(int nl,int nc,  char x)
    : _nlines(nl), _ncols(nc), _lines(nl, Vector(nc, x))
{
}

/*!
 *  This operator makes it possible to use char indexing with a Matrix
 *  (mat[i][ j])
 */
Vector& Matrix::operator[](int i)
{
    if (i < 0 || i >= _nlines) throw Out_Of_Bounds();
    return _lines[i];
}

/*!
 *  This operator makes it possible to use char indexing with a Matrix
 *  (mat[i][ j])
 */
const Vector& Matrix::operator[](int i) const
{
    if (i < 0 || i >= _nlines) throw Out_Of_Bounds();
    return _lines[i];
}


char& Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= _nlines || j < 0 || j >= _ncols) throw Out_Of_Bounds();
    return _lines[i][j];
}

char Matrix::operator()(int i, int j) const
{
    if (i < 0 || i >= _nlines || j < 0 || j >= _ncols) throw Out_Of_Bounds();
    return _lines[i][j];
}

/*!
 *  We print each line of the matrix as an MVector on a single line.
 */
ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat._nlines; ++i)
        os << mat._lines[i] << endl;
    return os;
}

