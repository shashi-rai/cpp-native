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

#include "matrix.h"

namespace dsa {

Matrix::Matrix() : data(0, std::vector<double>(0, 0.0)) {

}

Matrix::Matrix(int dim) : data(dim, std::vector<double>(dim, 0.0)) {

}

Matrix::Matrix(int rows, int cols) : data(rows, std::vector<double>(cols, 0.0)) {

}

Matrix::~Matrix() {

}

void Matrix::set(double value) {
    int rows = getRows();
    int cols = getCols();

    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = value;	
	return;
}

void Matrix::set(int row, int col, double value) {
    data[row][col] = value;
}

double Matrix::get(int row, int col) const {
    return data[row][col];
}

int Matrix::getRows() const {
    return data.size();
}

int Matrix::getCols() const {
    return data[0].size();
}

void Matrix::resize(int rows, int cols) {
	data.resize(rows);
	for (int i = 0; i < rows; i++)
		data[i].resize(cols);				
	return;	
}

Matrix Matrix::copy() {
    int rows = getRows();
    int cols = getCols();
    Matrix fresh(rows, cols);
		
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			fresh(i, j) = data[i][j];	
	return fresh;
}

void Matrix::clear() {			
    int rows = getRows();
    int cols = getCols();

    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = 0.0;		
	return;	
}

void Matrix::rand(float min, float max) {
    int rows = getRows();
    int cols = getCols();
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(min, max);

	generator.seed(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = distribution(generator);
	return;
}

void Matrix::randnorm(float mean, float stddev) {
    int rows = getRows();
    int cols = getCols();
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mean, stddev);

	generator.seed(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = distribution(generator);
	return;
}

std::string Matrix::print() {
    std::stringstream result;
    int rows = getRows();
    int cols = getCols();

    if (rows == 0 && cols == 0)
		return "";			
	for (int i = 0; i < rows; i ++) {			
		result << "[ ";
		for (int j = 0; j < cols; j++) {			
			result << data[i][j] << " ";		
		}
		result << "]" << std::endl;		
	}
	return result.str();
}

} // namespace dsa
