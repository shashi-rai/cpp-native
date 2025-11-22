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

#include <iostream>
#include <vector>
#include "dsa/matrix.h"
#include "dsa/tensor.h"

int main() {
    dsa::Matrix mat(3, 3);
    mat.set(1, 1, 5.0);
    std::cout << "Matrix: " << mat.getRows() << " rows, " << mat.getCols() << " columns" << std::endl;
    std::cout << "Value at (1,1): " << mat.get(1, 1) << std::endl;

    dsa::Tensor tensor(2, 2);
    tensor.set(1, 1, mat);
    std::cout << "Tensor: ";
    std::cout << tensor.getRows() << " rows, " << tensor.getCols() << " columns" << std::endl;
    dsa::Matrix retrievedMat = tensor.get(1, 1);
    std::cout << "Retrieved Matrix from Tensor at (1,1): " << retrievedMat.getRows() << " rows, " << retrievedMat.getCols() << " columns" << std::endl;
    std::cout << "Value at (1,1) in retrieved Matrix: " << retrievedMat.get(1, 1) << std::endl;
    
    return 0;
}