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

#include "index.h"

namespace fin {

Index::Index() : act::Asset(), assets() {

}

Index::Index(std::string name)
        : act::Asset(name), assets() {

}

Index::Index(std::string name, const float value)
        : act::Asset(name, value), assets() {

}

Index::Index(const act::AssetArray& assets)
        : act::Asset(), assets(assets) {

}

Index::Index(std::string name, const act::AssetArray& assets)
        : act::Asset(name), assets(assets) {

}

Index::Index(std::string name, const float value, const act::AssetArray& assets)
        : act::Asset(name, value), assets(assets) {

}

Index::~Index() {

}

bool Index::operator==(const Index& peer) const {
    return (static_cast<const act::Asset&>(*this) == static_cast<const act::Asset&>(peer))
        && (assets == peer.assets);
}

Index Index::operator+(const Index& peer) const {
    act::AssetArray result(assets);
    result.insert(result.end(), peer.assets.begin(), peer.assets.end());
    return Index("+", (getValue() + peer.getValue()), result);
}

Index Index::operator-(const Index& peer) const {
    act::AssetArray result(assets);
    for (act::AssetArray::const_iterator it = peer.assets.begin(); it != peer.assets.end(); ++it) {
        act::AssetArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Index("-", (getValue() - peer.getValue()), result);
}

int Index::getAssetCount() const {
    return assets.size();
}

act::Asset Index::get(int index) const {
    act::Asset result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(assets.size())) {
        return result;
    }
    return assets[index];
}

void Index::set(int index, const act::Asset& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(assets.size())) {
        // replace existing element
        assets[index] = object;
    } else if (index == static_cast<int>(assets.size())) {
        // append at end
        assets.push_back(object);
    } else {
        // index beyond current size: append at end
        assets.push_back(object);
    }
    return;
}

act::Amount Index::copy() {
    Index fresh(getName(), getValue(), assets);
    return fresh;
}

void Index::clear() {
    act::Asset::clear();
    assets.clear();
    return;
}

std::string Index::print() {
    std::stringstream result;
    result << act::Asset::print() << ",sz:";
    result << assets.size();
	return result.str();
}

} // namespace fin