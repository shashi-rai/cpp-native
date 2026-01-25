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

#ifndef QFT_STRONG_H
#define QFT_STRONG_H

#include "neutron.h"
#include "nuclear.h"
#include "proton.h"

namespace qft {

class Strong : public Nuclear {

public:
    // Constructors
    Strong();
    Strong(std::string name);
    Strong(const std::shared_ptr<Field> field);
    Strong(std::string name, const std::shared_ptr<Field> field);
    Strong(const float magnitude);
    Strong(const float magnitude, const std::shared_ptr<Field> field);
    Strong(const float magnitude, const float direction);
    Strong(const float magnitude, const float direction, const std::shared_ptr<Field>field);
    Strong(const float magnitude, const float direction, const short int scaling);
    Strong(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field);
    Strong(std::string name, const float magnitude);
    Strong(std::string name, const float magnitude, const std::shared_ptr<Field> field);
    Strong(std::string name, const float magnitude, const float direction);
    Strong(std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field);
    Strong(std::string name, const float magnitude, const float direction,
        const short int scaling);
    Strong(std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field);

    // Destructors
    ~Strong();

    // Operator overloading
    bool operator==(const Strong& peer) const;

    // Access operator
    Strong operator()(const Proton& peerX, const Proton& peerY) const;
    Strong operator()(const Neutron& peerX, const Neutron& peerY) const;
    Strong operator()(const Proton& peerX, const Neutron& peerY) const;

    // Getters

    // Setters

    // Additional methods
    virtual Force copy();
    virtual void clear();
    virtual std::string print();

public:
    static const short int RANGE_SCALE;
};

typedef std::vector<Strong > StrongArray;

} // namespace qft

#endif //QFT_STRONG_H