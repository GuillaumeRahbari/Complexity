//
//  Vector.cpp
//  Complexity
//
//  Created by Garrigos Fernando and Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Garrigos Fernando et Guillaume Rahbari . All rights reserved.
//

#include <numeric>
#include <cmath>
using namespace std;

#include "Vector.h"


/*!
 *  No surprise here: we simply call the adequate constructor of std::vector.
 *
 *  \param n number of elements 
 *  \param x the common value to initialize all components with
  */
Vector::Vector(int n, string x)
    : _ncomps(n), _components(n, x) 
{
    // Nothing else to do
}

string& Vector::operator[](int i)
{
    if (i < 0 || i >= _ncomps) throw Out_Of_Bounds();
    return _components[i];
}

string Vector::operator[](int i) const
{
    if (i < 0 || i >= _ncomps) throw Out_Of_Bounds();
    return _components[i];
}

/*!
 *  Enclose the list of component values.
 */
ostream& operator<<(ostream& os, const Vector& mv)
{
    for (int i = 0; i < mv._ncomps; ++i)
        os << mv._components[i];
    return os;
}

