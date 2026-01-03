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

#ifndef IMG_RASTER_H
#define IMG_RASTER_H

#include <climits>
#include <sstream>
#include <string>
#include <vector>
#include "rgb.h"

namespace img {

class Raster {
    std::string layer;
    std::vector<std::vector<RGB> > pixels;
public:
    // Constructors
    Raster();
    Raster(const int dim);
    Raster(const int rows, const int cols);
    Raster(const int rows, const int cols, const RGB& value);
    Raster(std::string layer);
    Raster(std::string layer, const int dim);
    Raster(std::string layer, const int rows, const int cols);
    Raster(std::string layer, const int rows, const int cols, const RGB& value);

    // Destructors
    ~Raster();

    // Access operator
    RGB operator()(const int row, const int col) { return pixels[row][col]; }
    const RGB operator()(const int row, const int col) const { return pixels[row][col]; }

    // Getters
    std::string getLayer() const { return layer; }

    // Setters
    void setLayer(const std::string& layer) { this->layer = layer; }

    // Additional methods
    void set(const RGB& value);
    void set(const int row, const int col, const RGB& value);
    RGB get(const int row, const int col) const;
    int getRows() const;
    int getCols() const;
    void resize(const int rows, const int cols);
    Raster copy() const;
    void clear();
    std::string print();
public:
    static const int ROWS_MIN;
    static const int ROWS_MAX;
    static const int COLS_MIN;
    static const int COLS_MAX;
};

typedef std::vector<Raster > RasterArray;

} // namespace img

#endif //IMG_RASTER_H