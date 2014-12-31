//
//  Matrix.h
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
using namespace std;

#include "Vector.h"


/*! \class Matrix
 *
 * \brief Simple mathematical matrices as used in linear algebra.
 *
 * A Matrix is implemented as an STL vector (std::vector) of Vector's.
*/

class Matrix
{
private:

    int _nlines;        //!< Number of lines.
    int _ncols;         //!< Number of columns.
    vector<Vector> _lines; //!< The elements themselves.
   
public:

    //! \class Index out of range exception.
    class Out_Of_Bounds {};

    //! \class Operation on vectors with incorrect dimensions exception.
    class Bad_Dimensions {};

    //! Constructor (also usable as default constructor).
    Matrix(int nl = 0, int nc = 0, char x = ' ');

    /*! \name Subscript
     *
     *  \exception Out_Of_Bounds thrown if index is outside range
     *
     * @{
     */
    //! A reference to the line at index i (version for a non-constant matrix).
    Vector& operator[](int i);
    //! A reference to the line at index i (version for a constant matrix).
    const Vector& operator[](int i) const;

    //! Access to element at indexes (i,j) (version for a non-constant matrix).
    char& operator()(int i, int j);
    //! Access to element at indexes (i,j) (version for aconstant matrix).
    char operator()(int i, int j) const;

    /*@}*/

    //! IO operation: just display the contents.
    friend ostream& operator<<(ostream& os, const Matrix& mat);
};


#endif
