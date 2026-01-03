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

#include <climits>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

namespace dsa {

class Matrix {
    std::vector<std::vector<double> > data;
public:
    // Constructors
    Matrix();
    Matrix(const int dim);
    Matrix(const int rows, const int cols);

    // Destructors
    ~Matrix();

    // Access operator
    double& operator()(const int row, const int col) { return data[row][col]; }
    const double& operator()(const int row, const int col) const { return data[row][col]; }

    // Additional methods
    void set(const double value);
    void set(const int row, const int col, const double value);
    double get(const int row, const int col) const;
    int getRows() const;
    int getCols() const;
    void resize(const int rows, const int cols);
    Matrix copy() const;
    void clear();
    void rand(const float min, const float max);
    void randnorm(const float mean, const float stddev);
    std::string print();
public:
    static const double DEFAULT_VALUE;
    static const int ROWS_MIN;
    static const int ROWS_MAX;
    static const int COLS_MIN;
    static const int COLS_MAX;
};

typedef std::vector<Matrix > MatrixArray;

} // namespace dsa

#endif //DSA_MATRIX_H