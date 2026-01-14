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

#include "promise.h"

namespace doc {

const std::string Promise::DEFAULT_REMARKS = "";

Promise::Promise()
        : statement(DEFAULT_REMARKS) {

}

Promise::Promise(const std::string statement)
        : statement(statement) {

}

Promise::~Promise() {

}

bool Promise::operator==(const Promise& peer) const {
    return (statement == peer.statement);
}

Promise Promise::copy() {
    Promise fresh(statement);
    return fresh;
}

void Promise::clear() {
    statement = DEFAULT_REMARKS;
    return;
}

std::string Promise::print() {
    std::stringstream result;
    result << statement;
	return result.str();
}

} // namespace doc