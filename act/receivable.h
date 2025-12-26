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

#ifndef ACT_RECEIVABLE_H
#define ACT_RECEIVABLE_H

#include <sstream>
#include <string>
#include <vector>
#include "account.h"
#include "batch.h"

namespace act {

class Receivable : public Account {
    Batch batch;
public:
    // Constructors
    Receivable();
    Receivable(std::string name);
    Receivable(const Currency& currency);
    Receivable(std::string name, const Currency& currency);
    Receivable(const Batch& batch);
    Receivable(std::string name, const Batch& batch);
    Receivable(const Batch& batch, const Currency& currency);
    Receivable(std::string name, const Batch& batch, const Currency& currency);

    // Destructors
    ~Receivable();

    // Operator overloading
    bool operator==(const Receivable& peer) const;
    Receivable operator+(const Receivable& peer) const;
    Receivable operator-(const Receivable& peer) const;

    // Getters
    Batch getBatch() const { return batch; }

    // Setters
    void setBatch(const Batch& posting) { this->batch = posting; }

    // Additional methods
    virtual Account copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Receivable > ReceivableArray;

} // namespace act

#endif //ACT_RECEIVABLE_H