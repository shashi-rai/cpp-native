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

#ifndef GRT_GALAXY_H
#define GRT_GALAXY_H

#include <string>
#include <vector>
#include "celestial.h"
#include "star.h"

namespace grt {

class Galaxy : public Celestial {
    StarArray stars;
public:
    // Constructors
    Galaxy();
    Galaxy(std::string name);
    Galaxy(std::string name, const StarArray& objects);

    // Destructors
    ~Galaxy();

    // Operator overloading
    bool operator==(const Galaxy& peer) const;
    Galaxy operator+(const Galaxy& peer) const;
    Galaxy operator-(const Galaxy& peer) const;

    // Access operator
    Star& operator()(int x) { return stars[x]; }
    const Star& operator()(int x) const { return stars[x]; }

    // Getters
    StarArray getStars() const { return stars; }

    // Setters
    void setStars(const StarArray& objects) { this->stars = objects; }

    // Additional methods
    int getStarCount() const;
    Star get(int index) const;
    void set(int index, const Star& object);
    virtual Celestial copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Galaxy > GalaxyArray;

} // namespace grt

#endif //GRT_GALAXY_H