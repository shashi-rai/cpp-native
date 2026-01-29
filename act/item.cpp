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

#include "item.h"

namespace act {

Item::Item() : name(), code(), cost(), sale(), batch(), quantity() {

}

Item::Item(const float quantity)
        : name(), code(), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const shp::Quantity& quantity)
        : name(), code(), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name)
        : name(name), code(), cost(), sale(), batch(), quantity() {

}

Item::Item(const std::string name, const float quantity)
        : name(name), code(), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const shp::Quantity& quantity)
        : name(name), code(), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code)
        : name(name), code(code), cost(), sale(), batch(), quantity() {

}

Item::Item(const std::string name, const std::string code, const float quantity)
        : name(name), code(code), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const shp::Quantity& quantity)
        : name(name), code(code), cost(), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const Batch& batch, const shp::Quantity& quantity)
        : name(name), code(code), cost(), sale(), batch(batch), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const shp::Quantity& quantity, const Cost& cost)
        : name(name), code(code), cost(cost), sale(), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const shp::Quantity& quantity, const Sale& sale)
        : name(name), code(code), cost(), sale(sale), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const shp::Quantity& quantity, const Cost& cost, const Sale& sale)
        : name(name), code(code), cost(cost), sale(sale), batch(), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const Batch& batch, const shp::Quantity& quantity, const Cost& cost)
        : name(name), code(code), cost(cost), sale(), batch(batch), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const Batch& batch, const shp::Quantity& quantity, const Sale& sale)
        : name(name), code(code), cost(), sale(sale), batch(batch), quantity(quantity) {

}

Item::Item(const std::string name, const std::string code, const Batch& batch, const shp::Quantity& quantity, const Cost& cost, const Sale& sale)
        : name(name), code(code), cost(cost), sale(sale), batch(batch), quantity(quantity) {

}

Item::~Item() {

}

bool Item::operator==(const Item& peer) const {
    return (name == peer.name) && (code == peer.code) && (batch == peer.batch);
}

Item Item::operator+(const Item& peer) const {
    return Item("+", code, batch, (quantity + peer.quantity), cost, sale);
}

Item Item::operator-(const Item& peer) const {
    return Item("-", code, batch, (quantity - peer.quantity), cost, sale);
}

Item Item::operator*(const Item& peer) const {
    return Item("*", code, batch, (quantity * peer.quantity), cost, sale);
}

Item Item::operator/(const Item& peer) const {
    return Item("/", code, batch, (quantity / peer.quantity), cost, sale);
}

Item Item::operator%(const Item& peer) const {
    return Item("%", code, batch, (quantity % peer.quantity), cost, sale);
}

Amount Item::getCostTotal() {
    float quantity_bought = getQuantity().getMagnitude();
    float cost_price = getCost().getAmount().getValue();
    float discount_received = getCost().getDiscount().getAmount().getValue();
    float value_added_tax = getCost().getTax().getPercent();
    float pretax_amount = (quantity_bought * (cost_price - discount_received));
    float posttax_amount = (pretax_amount + (pretax_amount * value_added_tax));
    Amount result(posttax_amount, getCost().getAmount().getCurrency());
    return result;
}

Amount Item::getSaleTotal() {
    float quantity_sold = getQuantity().getMagnitude();
    float sale_price = getSale().getAmount().getValue();
    float discount_provided = getSale().getDiscount().getAmount().getValue();
    float value_added_tax = getSale().getTax().getPercent();
    float pretax_amount = (quantity_sold * (sale_price - discount_provided));
    float posttax_amount = (pretax_amount + (pretax_amount * value_added_tax));
    Amount result(posttax_amount, getSale().getAmount().getCurrency());
    return result;
}

Item Item::copy() {
    Item fresh(name, code, batch, quantity, cost, sale);
    return fresh;
}

void Item::clear() {
    name = code = "";
    cost.clear();
    sale.clear();
    batch.clear();
    quantity.clear();
    return;
}

std::string Item::print() {
    std::stringstream result;
    result << name << ",";
    result << code << ",";
    result << cost.print() << ",";
    result << sale.print() << ",";
    result << batch.print() << ",";
    result << quantity.print() << ",";
    result << getCostTotal().print() << ",";
    result << getSaleTotal().print();
	return result.str();
}

} // namespace act