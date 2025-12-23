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

#include "usage.h"

namespace act {

Usage::Usage() : asset(), started(), stopped() {

}

Usage::Usage(const Asset& asset)
        : asset(asset), started(), stopped() {

}

Usage::Usage(const Asset& asset, const DateTime& started)
        : asset(asset), started(started), stopped() {

}

Usage::Usage(const Asset& asset, const DateTime& started, DateTime& stopped)
        : asset(asset), started(started), stopped(stopped) {

}

Usage::~Usage() {

}

bool Usage::operator==(const Usage& peer) const {
    return (asset == peer.asset)
        && (started == peer.started)
        && (stopped == peer.stopped);
}

Usage Usage::copy() {
    Usage fresh(asset, started, stopped);
    return fresh;
}

void Usage::clear() {
    asset.clear();
    started.clear();
    stopped.clear();
    return;
}

std::string Usage::print() {
    std::stringstream result;
    result << asset.print() << ",";
    result << started.print() << ",";
    result << stopped.print();
	return result.str();
}

} // namespace act