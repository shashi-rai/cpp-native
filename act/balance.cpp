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

Balance Balance::operator+(const Balance& peer) const {
    AssetArray newassets(assets);
    newassets.insert(newassets.end(), peer.assets.begin(), peer.assets.end());
    LiabilityArray newliabilities(liabilities);
    newliabilities.insert(newliabilities.end(), peer.liabilities.begin(), peer.liabilities.end());
    EquityArray newequities(equities);
    newequities.insert(newequities.end(), peer.equities.begin(), peer.equities.end());
    return Balance("+", newassets, newliabilities, newequities);
}

Balance Balance::operator-(const Balance& peer) const {
    AssetArray newassets(assets);
    for (AssetArray::const_iterator it = peer.assets.begin(); it != peer.assets.end(); ++it) {
        AssetArray::iterator found = std::find(newassets.begin(), newassets.end(), *it);
        if (found != newassets.end()) {
            newassets.erase(found);
        }
    }
    LiabilityArray newliabilities(liabilities);
    for (LiabilityArray::const_iterator it = peer.liabilities.begin(); it != peer.liabilities.end(); ++it) {
        LiabilityArray::iterator found = std::find(newliabilities.begin(), newliabilities.end(), *it);
        if (found != newliabilities.end()) {
            newliabilities.erase(found);
        }
    }
    EquityArray newequities(equities);
    for (EquityArray::const_iterator it = peer.equities.begin(); it != peer.equities.end(); ++it) {
        EquityArray::iterator found = std::find(newequities.begin(), newequities.end(), *it);
        if (found != newequities.end()) {
            newequities.erase(found);
        }
    }
    return Balance("-", newassets, newliabilities, newequities);
}

int Balance::getAssetCount() const {
    return assets.size();
}

Asset Balance::getAsset(int index) const {
    Asset result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(assets.size())) {
        return result;
    }
    return assets[index];
}

void Balance::setAsset(int index, const Asset& object) {
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

Amount Balance::getAssetTotal() const {
    Amount result(0);
    for (AssetArray::const_iterator it = assets.begin(); it != assets.end(); ++it) {
        float value = (*it).getValue();
        result = (result + value);
    }
    return result;
}

int Balance::getLiabilityCount() const {
    return liabilities.size();
}

Liability Balance::getLiability(int index) const {
    Liability result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(liabilities.size())) {
        return result;
    }
    return liabilities[index];
}

void Balance::setLiability(int index, const Liability& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(liabilities.size())) {
        // replace existing element
        liabilities[index] = object;
    } else if (index == static_cast<int>(liabilities.size())) {
        // append at end
        liabilities.push_back(object);
    } else {
        // index beyond current size: append at end
        liabilities.push_back(object);
    }
    return;
}

Amount Balance::getLiabilityTotal() const {
    Amount result(0);
    for (LiabilityArray::const_iterator it = liabilities.begin(); it != liabilities.end(); ++it) {
        float value = (*it).getValue();
        result = (result + value);
    }
    return result;
}

int Balance::getEquityCount() const {
    return equities.size();
}

Equity Balance::getEquity(int index) const {
    Equity result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(equities.size())) {
        return result;
    }
    return equities[index];
}

void Balance::setEquity(int index, const Equity& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(equities.size())) {
        // replace existing element
        equities[index] = object;
    } else if (index == static_cast<int>(equities.size())) {
        // append at end
        equities.push_back(object);
    } else {
        // index beyond current size: append at end
        equities.push_back(object);
    }
    return;
}

Amount Balance::getEquityTotal() const {
    Amount result(0);
    for (EquityArray::const_iterator it = equities.begin(); it != equities.end(); ++it) {
        float value = (*it).getValue();
        result = (result + value);
    }
    return result;
}

doc::Document Balance::copy() {
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
    result << Report::print() << ",A![";
    result << assets.size() << "],L![";
    result << liabilities.size() << "],E![";
    result << equities.size() << "]";
	return result.str();
}

} // namespace act