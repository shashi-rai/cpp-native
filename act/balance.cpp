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

#include "balance.h"

namespace act {

Balance::Balance()
    : Report(), assets(), liabilities(), equities() {

}

Balance::Balance(std::string name)
    : Report(name), assets(), liabilities(), equities() {

}

Balance::Balance(const AssetArray& assets)
    : Report(), assets(assets), liabilities(), equities() {

}

Balance::Balance(const AssetArray& assets,
        const LiabilityArray& liabilities)
    : Report(), assets(assets), liabilities(liabilities), equities() {

}

Balance::Balance(const AssetArray& assets,
        const LiabilityArray& liabilities, const EquityArray& equities)
    : Report(), assets(assets), liabilities(liabilities), equities(equities) {

}

Balance::Balance(std::string name, const AssetArray& assets)
    : Report(name), assets(assets), liabilities(), equities() {

}

Balance::Balance(std::string name, const AssetArray& assets,
        const LiabilityArray& liabilities)
    : Report(name), assets(assets), liabilities(liabilities), equities() {

}

Balance::Balance(std::string name, const AssetArray& assets,
        const LiabilityArray& liabilities, const EquityArray& equities)
    : Report(name), assets(assets), liabilities(liabilities), equities(equities) {

}

Balance::~Balance() {

}

bool Balance::operator==(const Balance& peer) const {
    return (static_cast<const Report&>(*this) == static_cast<const Report&>(peer))
        && (assets == peer.assets)
        && (liabilities == peer.liabilities)
        && (equities == peer.equities);
}

Document Balance::copy() {
    Balance fresh(getName(), assets, liabilities, equities);
    return fresh;
}

void Balance::clear() {
    Report::clear();
    assets.clear();
    liabilities.clear();
    equities.clear();
    return;
}

std::string Balance::print() {
    std::stringstream result;
    result << Report::print() << ",a:";
    result << assets.size() << ",l:";
    result << liabilities.size() << ",e:";
    result << equities.size();
	return result.str();
}

} // namespace act