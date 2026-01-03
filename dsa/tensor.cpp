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

const double Tensor::DEFAULT_VALUE = 0.0;
const int Tensor::DIMS_MIN = 0;
const int Tensor::DIMS_MAX = INT_MAX;
const int Tensor::ROWS_MIN = 0;
const int Tensor::ROWS_MAX = INT_MAX;
const int Tensor::COLS_MIN = 0;
const int Tensor::COLS_MAX = INT_MAX;

Tensor::Tensor()
		: matrices() {

}

Tensor::Tensor(const int dims)
		: matrices(std::vector<Matrix>(dims, Matrix())) {

}

Tensor::Tensor(const int dims, const int rows, const int cols)
        : matrices(std::vector<Matrix>(dims, Matrix(rows, cols))) {

}

Tensor::~Tensor() {

}

void Tensor::resize(const int dims, const int rows, const int cols) {
	matrices.resize(dims);	
	for (int d = DIMS_MIN; d < dims; d++)
		matrices[d].resize(rows, cols);
	return;
}

void Tensor::set(const double value) {
    int dims = getDims();
    for (int d = DIMS_MIN; d < dims; d++)
		matrices[d].set(value);
}

void Tensor::set(const int index, const double value) {
    matrices[index].set(value);
}

void Tensor::set(const int index, const Matrix& value) {
    matrices[index] = value.copy();
}

Matrix Tensor::get(const int index) const {
    return matrices[index];
}

int Tensor::getDims() const {
    return matrices.size();
}

int Tensor::getRows() const {
	if (matrices.empty())
        return ROWS_MIN;
	return matrices[ROWS_MIN].getRows();
}

int Tensor::getCols() const {
	if (matrices.empty())
        return COLS_MIN;
	return matrices[ROWS_MIN].getCols();
}

Tensor Tensor::copy() const {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();

	Tensor fresh(dims, rows, cols);
	for (int d = DIMS_MIN; d < dims; d++)
		for (int i = ROWS_MIN; i < rows; i++)
			for (int j = COLS_MIN; j < cols; j++)
				fresh(d, i, j) = matrices[d](i, j);	
	return fresh;
}

void Tensor::clear() {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();

    for (int d = DIMS_MIN; d < dims; d++)
		for (int i = ROWS_MIN; i < rows; i++)
			for (int j = COLS_MIN; j < cols; j++)
				matrices[d](i, j) = DEFAULT_VALUE;
	return;
}

void Tensor::rand(const float min, const float max) {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();
    std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(min, max);

	generator.seed(time(0));
	for (int d = DIMS_MIN; d < dims; d++)
		for (int i = ROWS_MIN; i < rows; i++)
			for (int j = COLS_MIN; j < cols; j++)
				matrices[d](i, j) = distribution(generator);
	return;
}

void Tensor::randnorm(const float mean, const float stddev) {
	int dims = getDims();
	int rows = getRows();
	int cols = getCols();
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mean, stddev);

	generator.seed(time(0));
	for (int d = DIMS_MIN; d < dims; d++)
		for (int i = ROWS_MIN; i < rows; i++)
			for (int j = COLS_MIN; j < cols; j++)
				matrices[d](i, j) = distribution(generator);
	return;
}

std::string Tensor::print() {
	std::stringstream result;
    int dims = getDims();

	for (int d = DIMS_MIN; d < dims; d++) {
		result << d << ":" << std::endl; 
		result << matrices[d].print();
	}		
	return result.str();
}

std::string Tensor::print(const int index) {
    return matrices[index].print();
}

} // namespace dsa
