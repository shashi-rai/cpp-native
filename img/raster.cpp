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

#include "raster.h"

namespace img {

const int Raster::ROWS_MIN = 0;
const int Raster::ROWS_MAX = INT_MAX;
const int Raster::COLS_MIN = 0;
const int Raster::COLS_MAX = INT_MAX;

Raster::Raster()
        : layer(), pixels(ROWS_MIN, std::vector<RGB>(COLS_MIN, RGB())) {

}

Raster::Raster(const int dim)
        : layer(), pixels(dim, std::vector<RGB>(dim, RGB())) {

}

Raster::Raster(const int rows, const int cols)
        : layer(), pixels(rows, std::vector<RGB>(cols, RGB())) {

}

Raster::Raster(const int rows, const int cols, const RGB& value)
        : layer(), pixels(rows, std::vector<RGB>(cols, value)) {

}

Raster::Raster(std::string layer)
        : layer(), pixels(ROWS_MIN, std::vector<RGB>(COLS_MIN, RGB())) {

}

Raster::Raster(std::string layer, const int dim)
        : layer(layer), pixels(dim, std::vector<RGB>(dim, RGB())) {

}

Raster::Raster(std::string layer, const int rows, const int cols)
        : layer(layer), pixels(rows, std::vector<RGB>(cols, RGB())) {

}

Raster::Raster(std::string layer, const int rows, const int cols, const RGB& value)
        : layer(layer), pixels(rows, std::vector<RGB>(cols, value)) {

}

Raster::~Raster() {

}

void Raster::set(const RGB& value) {
    int rows = getRows();
    int cols = getCols();

    for (int i = ROWS_MIN; i < rows; i++)
		for (int j = COLS_MIN; j < cols; j++)
			pixels[i][j] = value;	
	return;
}

void Raster::set(const int row, const int col, const RGB& value) {
    pixels[row][col] = value;
}

RGB Raster::get(const int row, const int col) const {
    return pixels[row][col];
}

int Raster::getRows() const {
    return pixels.size();
}

int Raster::getCols() const {
    return pixels[ROWS_MIN].size();
}

void Raster::resize(const int rows, const int cols) {
	pixels.resize(rows);
	for (int i = ROWS_MIN; i < rows; i++)
		pixels[i].resize(cols);				
	return;	
}

Raster Raster::copy() const {
    int rows = getRows();
    int cols = getCols();
    Raster fresh(rows, cols);
		
	for (int i = ROWS_MIN; i < rows; i++)
		for (int j = COLS_MIN; j < cols; j++)
			fresh(i, j) = pixels[i][j];	
	return fresh;
}

void Raster::clear() {			
    int rows = getRows();
    int cols = getCols();

    for (int i = ROWS_MIN; i < rows; i++)
		for (int j = COLS_MIN; j < cols; j++)
			pixels[i][j] = RGB();		
	return;	
}

std::string Raster::print() {
    std::stringstream result;
    int rows = getRows();
    int cols = getCols();

    if (rows == ROWS_MIN && cols == COLS_MIN)
		return "";			
	for (int i = ROWS_MIN; i < rows; i ++) {			
		result << "[ ";
		for (int j = COLS_MIN; j < cols; j++) {			
			result << pixels[i][j].print() << " ";		
		}
		result << "]" << std::endl;		
	}
	return result.str();
}

} // namespace img