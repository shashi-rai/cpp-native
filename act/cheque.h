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

#ifndef ACT_CHEQUE_H
#define ACT_CHEQUE_H

#include <sstream>
#include <string>
#include <vector>
#include "amount.h"
#include "datetime.h"
#include "party.h"
#include "staff.h"

namespace act {

class Cheque {
    Party receipient;
    Amount amount;
    Staff signatory;
public:
    // Constructors
    Cheque();
    Cheque(const Party& receipient);
    Cheque(const Amount& amount);
    Cheque(const Staff& signatory);
    Cheque(const Amount& amount, const Staff& signatory);
    Cheque(const Party& receipient, const Amount& amount);
    Cheque(const Party& receipient, const Amount& amount, const Staff& signatory);

    // Destructors
    ~Cheque();

    // Operator overloading
    bool operator==(const Cheque& peer) const;
    Cheque operator+(const Cheque& peer) const;
    Cheque operator-(const Cheque& peer) const;
    Cheque operator*(const Cheque& peer) const;
    Cheque operator/(const Cheque& peer) const;
    Cheque operator%(const Cheque& peer) const;

    // Getters
    Party getReceipient() const { return receipient; }
    Amount getAmount() const { return amount; }
    Staff getSignatory() const { return signatory; }

    // Setters
    void setReceipient(const Party& party) { this->receipient = party; }
    void setAmount(const Amount& value) { this->amount = value; }
    void setSignatory(const Staff& autorized) { this->signatory = autorized; }

    // Additional methods
    virtual Cheque copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Cheque > ChequeArray;

} // namespace act

#endif //ACT_CHEQUE_H