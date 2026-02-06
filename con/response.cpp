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

#include "response.h"

namespace con {

Response::Response()
        : Behaviour(), output() {

}

Response::Response(const shp::Signal& output)
        : Behaviour(), output(output) {

}

Response::Response(const std::string name)
        : Behaviour(name), output() {

}

Response::Response(const std::string name, const shp::Signal& output)
        : Behaviour(name), output(output) {

}

Response::~Response() {

}

bool Response::operator==(const Response& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (output == peer.output);
}

Response Response::operator+(const Response& peer) const {
    return Response("+", (output + peer.output));
}

Response Response::operator-(const Response& peer) const {
    return Response("-", (output - peer.output));
}

Response Response::operator*(const Response& peer) const {
    return Response("*", (output * peer.output));
}

Response Response::operator/(const Response& peer) const {
    return Response("/", (output / peer.output));
}

Response Response::operator%(const Response& peer) const {
    return Response("%", (output % peer.output));
}

std::string Response::getName() const {
    return Behaviour::getName();
}

void Response::setName(const std::string name) {
    Behaviour::setName(name);
}

Response Response::copy() const {
    Response fresh(this->getName(), this->output);
    return fresh;
}

void Response::clear() {
    Behaviour::clear();
    output.clear();
    return;
}

std::string Response::print() const {
    std::stringstream result;
    result << "r:";
	result << Behaviour::print();
    result << output.print();
	return result.str();
}

} // namespace con