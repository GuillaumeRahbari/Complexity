//
//  Vector.h
//  Complexity
//
//  Created by Garrigos Fernando and Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Garrigos Fernando et Guillaume Rahbari . All rights reserved.
//

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*! \class Vector
 *
 * \brief Simple mathematical vectors as used in linear algebra.
 *
 * Vector is implemented using an STL vector<char>.
*/

class Vector
{
private:

    int _ncomps;		//!< number of elements (redundant yet convenient)
    vector<string> _components;	//!< the std::vector containing the elements
   
public:

    //! \class Index out of range exception.
    class Out_Of_Bounds {};

    //! \class Operation on vectors with incorrect dimensions exception.
    class Bad_Dimensions {};

    //! Constructor (also usable as default constructor).
    Vector(int n = 0, string x = " ");

    /*! \name Subscript
     *
     * @{
     */
    //! Subscript for non-constant vectors.
    string& operator[](int i);
    //! Subscript for constant vectors.
    string operator[](int i) const;

    /*@}*/

    //! IO operation: just display the contents.
    friend ostream& operator<<(ostream& os, const Vector& mv);
};


#endif
