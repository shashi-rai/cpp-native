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

#ifndef QFT_COLOUR_H
#define QFT_COLOUR_H

#include "charge.h"
#include "../img/rgb.h"

namespace qft {

class Colour : public Charge {
    img::RGB colour;
public:
    // Constructors
    Colour();
    Colour(const std::shared_ptr<Field> field);
    Colour(const img::RGB& colour);
    Colour(const img::RGB& colour, const std::shared_ptr<Field> field);
    Colour(const std::string unit);
    Colour(const shp::Unit& unit);
    Colour(const img::RGB& colour, const shp::Unit& unit);
    Colour(const img::RGB& colour, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Colour(const float magnitude);
    Colour(const float magnitude, const std::string unit);
    Colour(const float magnitude, const shp::Unit& unit);
    Colour(const img::RGB& colour, const float magnitude, const shp::Unit& unit);
    Colour(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Colour(const img::RGB& colour, const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Colour(const float magnitude, const short int scaling);
    Colour(const img::RGB& colour, const float magnitude, const short int scaling);
    Colour(const float magnitude, const short int scaling, const std::shared_ptr<Field> field);
    Colour(const img::RGB& colour, const float magnitude, const short int scaling, const std::shared_ptr<Field> field);
    Colour(const float magnitude, const short int scaling, const std::string unit);
    Colour(const float magnitude, const short int scaling, const shp::Unit& unit);
    Colour(const img::RGB& colour, const float magnitude, const short int scaling, const shp::Unit& unit);
    Colour(const float magnitude, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Colour(const img::RGB& colour, const float magnitude, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Field> field);

    // Destructors
    ~Colour();

    // Operator overloading
    bool operator==(const Colour& peer) const;
    Colour operator+(const Colour& peer) const;
    Colour operator-(const Colour& peer) const;
    Colour operator*(const Colour& peer) const;
    Colour operator/(const Colour& peer) const;
    Colour operator%(const Colour& peer) const;

    // Getters
    img::RGB getColour() const { return colour; }

    // Setters
    void setColour(const img::RGB& object) { this->colour = object; }

    // Additional methods
    bool hasNoColour() const;
    float getRed() const;
    void setRed(const float value);
    float getGreen() const;
    void setGreen(const float value);
    float getBlue() const;
    void setBlue(const float value);
    virtual Charge copy();
    virtual void clear();
    virtual std::string print();

public:
    enum TYPE { RED, GREEN, BLUE, };
    static const float DEFAULT_VALUE;
};

typedef std::vector<Colour > ColourArray;

} // namespace qft

#endif //QFT_COLOUR_H