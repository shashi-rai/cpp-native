// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef DSA_MATRIX_H
#define DSA_MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
    std::vector<std::vector<double> > data;
public:
    // Constructors
    Matrix();
    Matrix(int rows);
    Matrix(int rows, int cols);

    // Access operator
    double& operator()(int row, int col) { return data[row][col]; }
    const double& operator()(int row, int col) const { return data[row][col]; }

    // Additional methods
    void set(int row, int col, double value);
    double get(int row, int col) const;
    int getRows() const;
    int getCols() const;
};

typedef std::vector<Matrix > MatrixArray;

#endif //DSA_MATRIX_H