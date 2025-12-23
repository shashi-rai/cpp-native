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

#ifndef ACT_USAGE_H
#define ACT_USAGE_H

#include <sstream>
#include <string>
#include <vector>
#include "asset.h"
#include "datetime.h"

namespace act {

class Usage {
    Asset asset;
    DateTime started;
    DateTime stopped;
public:
    // Constructors
    Usage();
    Usage(const Asset& asset);
    Usage(const Asset& asset, const DateTime& started);
    Usage(const Asset& asset, const DateTime& started, DateTime& stopped);

    // Destructors
    ~Usage();

    // Operator overloading
    bool operator==(const Usage& peer) const;

    // Getters
    Asset getAsset() const { return asset; }
    DateTime getStarted() const { return started; }
    DateTime getStopped() const { return stopped; }

    // Setters
    void setAsset(const Asset& object) { this->asset = object; }
    void setStarted(const DateTime& object) { this->started = object; }
    void setStopped(const DateTime& object) { this->stopped = object; }

    // Additional methods
    virtual Usage copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Usage > UsageArray;

} // namespace act

#endif //ACT_USAGE_H