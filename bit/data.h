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

#ifndef BIT_DATA_H
#define BIT_DATA_H

#include <sstream>
#include <string>
#include <vector>
#include "binary.h"

namespace bit {

class Data {
    std::string name;
    BinaryArray bytes;
public:
    // Constructors
    Data();
    Data(const BinaryArray& bytes);
    Data(std::string name);
    Data(std::string name, const BinaryArray& bytes);

    // Destructors
    ~Data();

    // Operator overloading
    bool operator==(const Data& peer) const;
    Data operator+(const Data& peer) const;
    Data operator-(const Data& peer) const;

    // Access operator
    Binary operator()(const int x) { return bytes[x]; }
    const Binary operator()(const int x) const { return bytes[x]; }

    // Getters
    std::string getName() const { return name; }
    BinaryArray getBytes() const { return bytes; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setBytes(const BinaryArray& data) { this->bytes = data; }

    // Additional methods
    int getByteCount() const;
    Binary get(const int index) const;
    void set(const int index, const Binary& object);
    virtual Data copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Data > DataArray;

} // namespace bit

#endif //BIT_DATA_H