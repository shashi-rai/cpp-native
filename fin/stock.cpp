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

#include "stock.h"

namespace fin {

Stock::Stock()
        : act::Asset(),
        earningPerShare(), priceToEarning(), priceEarningGrowth(), priceToBook(),
        returnOnEquity(), debtToEquity(), dividendYield(), operatingProfitMargin() {

}

Stock::Stock(const std::string name)
        : act::Asset(name), earningPerShare(), priceToEarning(), priceEarningGrowth(),
        priceToBook(), returnOnEquity(), debtToEquity(), dividendYield(), operatingProfitMargin() {

}

Stock::Stock(const std::string name, const act::Currency& currency)
        : act::Asset(name, currency, ""), earningPerShare(), priceToEarning(), priceEarningGrowth(),
        priceToBook(), returnOnEquity(), debtToEquity(), dividendYield(), operatingProfitMargin() {

}

Stock::~Stock() {

}

bool Stock::operator==(const Stock& peer) const {
    return (static_cast<const act::Asset&>(*this) == static_cast<const act::Asset&>(peer));
}

Stock Stock::operator+(const Stock& peer) const {
    Stock result("+");
    result.setEarningPerShare(earningPerShare + peer.earningPerShare);
    result.setPriceToEarning(priceToEarning + peer.priceToEarning);
    result.setPriceEarningGrowth(priceEarningGrowth + peer.priceEarningGrowth);
    result.setPriceToBook(priceToBook + peer.priceToBook);
    result.setReturnOnEquity(returnOnEquity + peer.returnOnEquity);
    result.setDebtToEquity(debtToEquity + peer.debtToEquity);
    result.setDividendYield(dividendYield + peer.dividendYield);
    result.setOperatingProfitMargin(operatingProfitMargin + peer.operatingProfitMargin);
    return result;
}

Stock Stock::operator-(const Stock& peer) const {
    Stock result("-");
    result.setEarningPerShare(earningPerShare - peer.earningPerShare);
    result.setPriceToEarning(priceToEarning - peer.priceToEarning);
    result.setPriceEarningGrowth(priceEarningGrowth - peer.priceEarningGrowth);
    result.setPriceToBook(priceToBook - peer.priceToBook);
    result.setReturnOnEquity(returnOnEquity - peer.returnOnEquity);
    result.setDebtToEquity(debtToEquity - peer.debtToEquity);
    result.setDividendYield(dividendYield - peer.dividendYield);
    result.setOperatingProfitMargin(operatingProfitMargin - peer.operatingProfitMargin);
    return result;
}

Stock Stock::operator*(const Stock& peer) const {
    Stock result("*");
    result.setEarningPerShare(earningPerShare * peer.earningPerShare);
    result.setPriceToEarning(priceToEarning * peer.priceToEarning);
    result.setPriceEarningGrowth(priceEarningGrowth * peer.priceEarningGrowth);
    result.setPriceToBook(priceToBook * peer.priceToBook);
    result.setReturnOnEquity(returnOnEquity * peer.returnOnEquity);
    result.setDebtToEquity(debtToEquity * peer.debtToEquity);
    result.setDividendYield(dividendYield * peer.dividendYield);
    result.setOperatingProfitMargin(operatingProfitMargin * peer.operatingProfitMargin);
    return result;
}

Stock Stock::operator/(const Stock& peer) const {
    Stock result("/");
    result.setEarningPerShare(earningPerShare / peer.earningPerShare);
    result.setPriceToEarning(priceToEarning / peer.priceToEarning);
    result.setPriceEarningGrowth(priceEarningGrowth / peer.priceEarningGrowth);
    result.setPriceToBook(priceToBook / peer.priceToBook);
    result.setReturnOnEquity(returnOnEquity / peer.returnOnEquity);
    result.setDebtToEquity(debtToEquity / peer.debtToEquity);
    result.setDividendYield(dividendYield / peer.dividendYield);
    result.setOperatingProfitMargin(operatingProfitMargin / peer.operatingProfitMargin);
    return result;
}

Stock Stock::operator%(const Stock& peer) const {
    Stock result("%");
    result.setEarningPerShare(fmod(earningPerShare, peer.earningPerShare));
    result.setPriceToEarning(fmod(priceToEarning, peer.priceToEarning));
    result.setPriceEarningGrowth(fmod(priceEarningGrowth, peer.priceEarningGrowth));
    result.setPriceToBook(fmod(priceToBook, peer.priceToBook));
    result.setReturnOnEquity(fmod(returnOnEquity, peer.returnOnEquity));
    result.setDebtToEquity(fmod(debtToEquity, peer.debtToEquity));
    result.setDividendYield(fmod(dividendYield, peer.dividendYield));
    result.setOperatingProfitMargin(fmod(operatingProfitMargin, peer.operatingProfitMargin));
    return result;
}

act::Amount Stock::copy() {
    Stock result(getName(), getCurrency());
    result.setEarningPerShare(earningPerShare);
    result.setPriceToEarning(priceToEarning);
    result.setPriceEarningGrowth(priceEarningGrowth);
    result.setPriceToBook(priceToBook);
    result.setReturnOnEquity(returnOnEquity);
    result.setDebtToEquity(debtToEquity);
    result.setDividendYield(dividendYield);
    result.setOperatingProfitMargin(operatingProfitMargin);
    return result;
}

void Stock::clear() {
    act::Asset::clear();
    earningPerShare = priceToEarning = priceEarningGrowth = priceToBook = 0.0f;
    returnOnEquity = debtToEquity = dividendYield = operatingProfitMargin = 0.0f;
    return;
}

std::string Stock::print() {
    std::stringstream result;
    result << act::Asset::print() << ",{eps:";
    result << earningPerShare << ",pe:";
    result << priceToEarning << ",peg:";
    result << priceEarningGrowth << ",pb:";
    result << priceToBook << ",roe:";
    result << returnOnEquity << ",de:";
    result << debtToEquity << ",dy:";
    result << dividendYield << ",opm:";
    result << operatingProfitMargin << "}";
	return result.str();
}

} // namespace fin