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

#ifndef SHP_PHASE_H
#define SHP_PHASE_H

#include <string>
#include <vector>
#include "point.h"

namespace shp {

class Phase : public Point {
    long timestamp;
public:
    // Constructors
    Phase();
    Phase(std::string name);
    Phase(std::string name, long timestamp);

    // Destructors
    ~Phase();

    // Operator overloading
    bool operator==(const Phase& peer) const;

    // Getters
    long getTimestamp() const { return timestamp; }

    // Setters
    void setTimestamp(long value) { this->timestamp = value; }

    // Additional methods
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Phase > PhaseArray;

} // namespace shp

#endif //SHP_PHASE_H