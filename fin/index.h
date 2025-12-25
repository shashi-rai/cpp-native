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

#ifndef FIN_INDEX_H
#define FIN_INDEX_H

#include <sstream>
#include <string>
#include <vector>
#include "../act/asset.h"

namespace fin {

class Index : public act::Asset {
    act::AssetArray assets;
public:
    // Constructors
    Index();
    Index(std::string name);
    Index(std::string name, const float value);
    Index(const act::AssetArray& assets);
    Index(std::string name, const act::AssetArray& assets);
    Index(std::string name, const float value, const act::AssetArray& assets);

    // Destructors
    ~Index();

    // Operator overloading
    bool operator==(const Index& peer) const;
    Index operator+(const Index& peer) const;
    Index operator-(const Index& peer) const;

    // Access operator
    act::Asset& operator()(int x) { return assets[x]; }
    const act::Asset& operator()(int x) const { return assets[x]; }

    // Getters
    act::AssetArray getAssets() const { return assets; }

    // Setters
    void setAssets(const act::AssetArray& object) { this->assets = object; }

    // Additional methods
    int getAssetCount() const;
    act::Asset get(int index) const;
    void set(int index, const act::Asset& object);
    virtual act::Amount copy();
    virtual void clear();
    virtual std::string print();
public:
    static const float DEFAULT_VALUE;
};

typedef std::vector<Index > IndexArray;

} // namespace fin

#endif //FIN_INDEX_H