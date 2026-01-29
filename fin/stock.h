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

#ifndef FIN_STOCK_H
#define FIN_STOCK_H

#include "../act/asset.h"
#include "../act/currency.h"

namespace fin {

class Stock : public act::Asset {
    float earningPerShare;
    float priceToEarning;
    float priceEarningGrowth;
    float priceToBook;
    float returnOnEquity;
    float debtToEquity;
    float dividendYield;
    float operatingProfitMargin;
public:
    // Constructors
    Stock();
    Stock(const std::string name);
    Stock(const std::string name, const act::Currency& currency);

    // Destructors
    ~Stock();

    // Operator overloading
    bool operator==(const Stock& peer) const;
    Stock operator+(const Stock& peer) const;
    Stock operator-(const Stock& peer) const;
    Stock operator*(const Stock& peer) const;
    Stock operator/(const Stock& peer) const;
    Stock operator%(const Stock& peer) const;

    // Getters
    float getEarningPerShare() const { return earningPerShare; }
    float getPriceToEarning() const { return priceToEarning; }
    float getPriceEarningGrowth() const { return priceEarningGrowth; }
    float getPriceToBook() const { return priceToBook; }
    float getReturnOnEquity() const { return returnOnEquity; }
    float getDebtToEquity() const { return debtToEquity; }
    float getDividendYield() const { return dividendYield; }
    float getOperatingProfitMargin() const { return operatingProfitMargin; }

    // Setters
    void setEarningPerShare(const float value) { this->earningPerShare = value; }
    void setPriceToEarning(const float value) { this->priceToEarning = value; }
    void setPriceEarningGrowth(const float value) { this->priceEarningGrowth = value; }
    void setPriceToBook(const float value) { this->priceToBook = value; }
    void setReturnOnEquity(const float value) { this->returnOnEquity = value; }
    void setDebtToEquity(const float value) { this->debtToEquity = value; }
    void setDividendYield(const float value) { this->dividendYield = value; }
    void setOperatingProfitMargin(const float value) { this->operatingProfitMargin = value; }

    // Additional methods
    virtual act::Amount copy();
    virtual void clear();
    virtual std::string print();
public:
    static const float DEFAULT_VALUE;
};

typedef std::vector<Stock > StockArray;

} // namespace fin

#endif //FIN_STOCK_H