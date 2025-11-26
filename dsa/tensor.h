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

#ifndef DSA_TENSOR_H
#define DSA_TENSOR_H

#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
#include "matrix.h"

namespace dsa {

class Tensor {
    MatrixArray matrices;
public:
    // Constructors
    Tensor();
    Tensor(int dims);
    Tensor(int dims, int rows, int cols);

    // Destructors
    ~Tensor();

    // Access operator
    Matrix& operator()(int index) { return matrices[index]; }
    const Matrix& operator()(int index) const { return matrices[index]; }

    double& operator()(int dim, int row, int col) { return matrices[dim](row, col); }
	const double& operator()(int dim, int row, int col) const { return matrices[dim](row, col); }

    // Additional methods
    void set(double value);
    void set(int index, double value);
    void set(int index, Matrix value);
    Matrix get(int index) const;
    int getDims() const;
    int getRows() const;
    int getCols() const;
    Tensor copy();
    void clear();
    void rand(float min, float max);
    void randnorm(float mean, float stddev);
    std::string print();
    std::string print(int index);
private:
    void resize(int dims, int rows, int cols);
};

typedef std::vector<Tensor > TensorArray;

} // namespace dsa

#endif //DSA_TENSOR_H