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

#include "tensor.h"

namespace dsa {

Tensor::Tensor() : matrices() {

}

Tensor::Tensor(int dims) : matrices(std::vector<Matrix>(dims, Matrix())) {

}

Tensor::Tensor(int dims, int rows, int cols)
        : matrices(std::vector<Matrix>(dims, Matrix(rows, cols))) {

}

Tensor::~Tensor() {

}

void Tensor::resize(int dims, int rows, int cols) {
	matrices.resize(dims);	
	for (int d = 0; d < dims; d++)
		matrices[d].resize(rows, cols);
	return;
}

void Tensor::set(double value) {
    int dims = getDims();
    for (int d = 0; d < dims; d++)
		matrices[d].set(value);
}

void Tensor::set(int index, double value) {
    matrices[index].set(value);
}

void Tensor::set(int index, Matrix value) {
    matrices[index] = value.copy();
}

Matrix Tensor::get(int index) const {
    return matrices[index];
}

int Tensor::getDims() const {
    return matrices.size();
}

int Tensor::getRows() const {
	if (matrices.empty())
        return 0;
	return matrices[0].getRows();
}

int Tensor::getCols() const {
	if (matrices.empty())
        return 0;
	return matrices[0].getCols();
}

Tensor Tensor::copy() {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();

	Tensor fresh(dims, rows, cols);
	for (int d = 0; d < dims; d++)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fresh(d, i, j) = matrices[d](i, j);	
	return fresh;
}

void Tensor::clear() {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();

    for (int d = 0; d < dims; d++)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrices[d](i, j) = 0.0;
	return;
}

void Tensor::rand(float min, float max) {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();
    std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(min, max);

	generator.seed(time(0));
	for (int d = 0; d < dims; d++)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrices[d](i, j) = distribution(generator);
	return;
}

void Tensor::randnorm(float mean, float stddev) {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mean, stddev);

	generator.seed(time(0));
	for (int d = 0; d < dims; d++)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrices[d](i, j) = distribution(generator);
	return;
}

void Tensor::print() {
    int dims = getDims();

	for (int d = 0; d < dims; d++) {
		std::cout << d << ":\n"; 
		matrices[d].print();
	}		
	return;
}

void Tensor::print(int index) {
    matrices[index].print();
	return;
}

} // namespace dsa
