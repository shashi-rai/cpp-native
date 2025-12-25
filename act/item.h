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

#ifndef ACT_ITEM_H
#define ACT_ITEM_H

#include <sstream>
#include <string>
#include <vector>
#include "batch.h"
#include "cost.h"
#include "sale.h"
#include "../shp/quantity.h"

namespace act {

class Item {
    std::string name;
    std::string code;
    Cost cost;
    Sale sale;
    Batch batch;
    shp::Quantity quantity;
public:
    // Constructors
    Item();
    Item(const float quantity);
    Item(const shp::Quantity& quantity);
    Item(std::string name);
    Item(std::string name, const float quantity);
    Item(std::string name, const shp::Quantity& quantity);
    Item(std::string name, std::string code);
    Item(std::string name, std::string code, const float quantity);
    Item(std::string name, std::string code, const shp::Quantity& quantity);
    Item(std::string name, std::string code, const Batch& batch, const shp::Quantity& quantity);
    Item(std::string name, std::string code, const shp::Quantity& quantity, const Cost& cost);
    Item(std::string name, std::string code, const shp::Quantity& quantity, const Sale& sale);
    Item(std::string name, std::string code, const shp::Quantity& quantity, const Cost& cost, const Sale& sale);
    Item(std::string name, std::string code, const Batch& batch, const shp::Quantity& quantity, const Cost& cost);
    Item(std::string name, std::string code, const Batch& batch, const shp::Quantity& quantity, const Sale& sale);
    Item(std::string name, std::string code, const Batch& batch, const shp::Quantity& quantity, const Cost& cost, const Sale& sale);

    // Destructors
    ~Item();

    // Operator overloading
    bool operator==(const Item& peer) const;
    Item operator+(const Item& peer) const;
    Item operator-(const Item& peer) const;
    Item operator*(const Item& peer) const;
    Item operator/(const Item& peer) const;
    Item operator%(const Item& peer) const;

    // Getters
    std::string getName() const { return name; }
    std::string getCode() const { return code; }
    Cost getCost() const { return cost; }
    Sale getSale() const { return sale; }
    Batch getBatch() const { return batch; }
    shp::Quantity getQuantity() const { return quantity; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCode(const std::string& number) { this->code = number; }
    void setCost(const Cost& object) { this->cost = object; }
    void setSale(const Sale& object) { this->sale = object; }
    void setBatch(const Batch& object) { this->batch = object; }
    void setQuantity(const shp::Quantity& object) { this->quantity = object; }

    // Additional methods
    virtual Amount getCostTotal();
    virtual Amount getSaleTotal();
    virtual Item copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Item > ItemArray;

} // namespace act

#endif //ACT_ITEM_H