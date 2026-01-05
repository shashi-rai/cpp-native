# Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

CPPTOOL	 = g++
CXXINCS  = -I"../inc" 
CXXFLAGS = $(CXXINCS) -std=c++11
RMCLEAN	 = rm -f

LIBMAKR	 = ar
LIBFOLDR = ../lib
LIBNAME	 = libact.a
LIBFILES = $(LIBFOLDR)/$(LIBNAME)
OBJFOLDR = ../obj
OBJFILES = $(OBJFOLDR)/*.o

.PHONY: all all-before all-after clean clean-custom

all: all-before \
	$(LIBFOLDR)/$(LIBNAME) \
	all-after

clean: clean-custom clean-objs clean-libs

clean-objs: clean-custom
	${RMCLEAN} $(OBJFILES)

clean-libs: clean-custom
	${RMCLEAN} $(LIBFILES)

$(LIBFOLDR)/$(LIBNAME): \
		$(OBJFOLDR)/account.o \
		$(OBJFOLDR)/agency.o \
		$(OBJFOLDR)/amount.o \
		$(OBJFOLDR)/asset.o \
		$(OBJFOLDR)/balance.o \
		$(OBJFOLDR)/bank.o \
		$(OBJFOLDR)/batch.o \
		$(OBJFOLDR)/branch.o \
		$(OBJFOLDR)/brand.o \
		$(OBJFOLDR)/business.o \
		$(OBJFOLDR)/cash.o \
		$(OBJFOLDR)/charges.o \
		$(OBJFOLDR)/chart.o \
		$(OBJFOLDR)/cheque.o \
		$(OBJFOLDR)/contract.o \
		$(OBJFOLDR)/cost.o \
		$(OBJFOLDR)/country.o \
		$(OBJFOLDR)/coupon.o \
		$(OBJFOLDR)/currency.o \
		$(OBJFOLDR)/customer.o \
		$(OBJFOLDR)/datetime.o \
		$(OBJFOLDR)/department.o \
		$(OBJFOLDR)/depot.o \
		$(OBJFOLDR)/depreciation.o \
		$(OBJFOLDR)/discount.o \
		$(OBJFOLDR)/distributor.o \
		$(OBJFOLDR)/dividend.o \
		$(OBJFOLDR)/employee.o \
		$(OBJFOLDR)/equity.o \
		$(OBJFOLDR)/expense.o \
		$(OBJFOLDR)/factory.o \
		$(OBJFOLDR)/fees.o \
		$(OBJFOLDR)/fiscal.o \
		$(OBJFOLDR)/government.o \
		$(OBJFOLDR)/income.o \
		$(OBJFOLDR)/interest.o \
		$(OBJFOLDR)/inventory.o \
		$(OBJFOLDR)/invoice.o \
		$(OBJFOLDR)/item.o \
		$(OBJFOLDR)/ledger.o \
		$(OBJFOLDR)/liability.o \
		$(OBJFOLDR)/loan.o \
		$(OBJFOLDR)/manufacturer.o \
		$(OBJFOLDR)/milestone.o \
		$(OBJFOLDR)/office.o \
		$(OBJFOLDR)/order.o \
		$(OBJFOLDR)/party.o \
		$(OBJFOLDR)/payable.o \
		$(OBJFOLDR)/payment.o \
		$(OBJFOLDR)/person.o \
		$(OBJFOLDR)/price.o \
		$(OBJFOLDR)/product.o \
		$(OBJFOLDR)/project.o \
		$(OBJFOLDR)/purchase.o \
		$(OBJFOLDR)/quote.o \
		$(OBJFOLDR)/receivable.o \
		$(OBJFOLDR)/report.o \
		$(OBJFOLDR)/retailer.o \
		$(OBJFOLDR)/revenue.o \
		$(OBJFOLDR)/role.o \
		$(OBJFOLDR)/sale.o \
		$(OBJFOLDR)/service.o \
		$(OBJFOLDR)/staff.o \
		$(OBJFOLDR)/store.o \
		$(OBJFOLDR)/supplier.o \
		$(OBJFOLDR)/task.o \
		$(OBJFOLDR)/tax.o \
		$(OBJFOLDR)/trade.o \
		$(OBJFOLDR)/transaction.o \
		$(OBJFOLDR)/transporter.o \
		$(OBJFOLDR)/usage.o \
		$(OBJFOLDR)/vehicle.o \
		$(OBJFOLDR)/warehouse.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/account.o \
		$(OBJFOLDR)/agency.o \
		$(OBJFOLDR)/amount.o \
		$(OBJFOLDR)/asset.o \
		$(OBJFOLDR)/balance.o \
		$(OBJFOLDR)/bank.o \
		$(OBJFOLDR)/batch.o \
		$(OBJFOLDR)/branch.o \
		$(OBJFOLDR)/brand.o \
		$(OBJFOLDR)/business.o \
		$(OBJFOLDR)/cash.o \
		$(OBJFOLDR)/charges.o \
		$(OBJFOLDR)/chart.o \
		$(OBJFOLDR)/cheque.o \
		$(OBJFOLDR)/contract.o \
		$(OBJFOLDR)/cost.o \
		$(OBJFOLDR)/country.o \
		$(OBJFOLDR)/coupon.o \
		$(OBJFOLDR)/currency.o \
		$(OBJFOLDR)/customer.o \
		$(OBJFOLDR)/datetime.o \
		$(OBJFOLDR)/department.o \
		$(OBJFOLDR)/depot.o \
		$(OBJFOLDR)/depreciation.o \
		$(OBJFOLDR)/discount.o \
		$(OBJFOLDR)/distributor.o \
		$(OBJFOLDR)/dividend.o \
		$(OBJFOLDR)/employee.o \
		$(OBJFOLDR)/equity.o \
		$(OBJFOLDR)/expense.o \
		$(OBJFOLDR)/factory.o \
		$(OBJFOLDR)/fees.o \
		$(OBJFOLDR)/fiscal.o \
		$(OBJFOLDR)/government.o \
		$(OBJFOLDR)/income.o \
		$(OBJFOLDR)/interest.o \
		$(OBJFOLDR)/inventory.o \
		$(OBJFOLDR)/invoice.o \
		$(OBJFOLDR)/item.o \
		$(OBJFOLDR)/ledger.o \
		$(OBJFOLDR)/liability.o \
		$(OBJFOLDR)/loan.o \
		$(OBJFOLDR)/manufacturer.o \
		$(OBJFOLDR)/milestone.o \
		$(OBJFOLDR)/office.o \
		$(OBJFOLDR)/order.o \
		$(OBJFOLDR)/party.o \
		$(OBJFOLDR)/payable.o \
		$(OBJFOLDR)/payment.o \
		$(OBJFOLDR)/person.o \
		$(OBJFOLDR)/price.o \
		$(OBJFOLDR)/product.o \
		$(OBJFOLDR)/project.o \
		$(OBJFOLDR)/purchase.o \
		$(OBJFOLDR)/quote.o \
		$(OBJFOLDR)/receivable.o \
		$(OBJFOLDR)/report.o \
		$(OBJFOLDR)/retailer.o \
		$(OBJFOLDR)/revenue.o \
		$(OBJFOLDR)/role.o \
		$(OBJFOLDR)/sale.o \
		$(OBJFOLDR)/service.o \
		$(OBJFOLDR)/staff.o \
		$(OBJFOLDR)/store.o \
		$(OBJFOLDR)/supplier.o \
		$(OBJFOLDR)/task.o \
		$(OBJFOLDR)/tax.o \
		$(OBJFOLDR)/trade.o \
		$(OBJFOLDR)/transaction.o \
		$(OBJFOLDR)/transporter.o \
		$(OBJFOLDR)/usage.o \
		$(OBJFOLDR)/vehicle.o \
		$(OBJFOLDR)/warehouse.o

$(OBJFOLDR)/account.o: account.cpp
	$(CPPTOOL) -c account.cpp -o $(OBJFOLDR)/account.o $(CXXFLAGS)

$(OBJFOLDR)/agency.o: agency.cpp
	$(CPPTOOL) -c agency.cpp -o $(OBJFOLDR)/agency.o $(CXXFLAGS)

$(OBJFOLDR)/amount.o: amount.cpp
	$(CPPTOOL) -c amount.cpp -o $(OBJFOLDR)/amount.o $(CXXFLAGS)

$(OBJFOLDR)/asset.o: asset.cpp
	$(CPPTOOL) -c asset.cpp -o $(OBJFOLDR)/asset.o $(CXXFLAGS)

$(OBJFOLDR)/balance.o: balance.cpp
	$(CPPTOOL) -c balance.cpp -o $(OBJFOLDR)/balance.o $(CXXFLAGS)

$(OBJFOLDR)/bank.o: bank.cpp
	$(CPPTOOL) -c bank.cpp -o $(OBJFOLDR)/bank.o $(CXXFLAGS)

$(OBJFOLDR)/batch.o: batch.cpp
	$(CPPTOOL) -c batch.cpp -o $(OBJFOLDR)/batch.o $(CXXFLAGS)

$(OBJFOLDR)/branch.o: branch.cpp
	$(CPPTOOL) -c branch.cpp -o $(OBJFOLDR)/branch.o $(CXXFLAGS)

$(OBJFOLDR)/brand.o: brand.cpp
	$(CPPTOOL) -c brand.cpp -o $(OBJFOLDR)/brand.o $(CXXFLAGS)

$(OBJFOLDR)/business.o: business.cpp
	$(CPPTOOL) -c business.cpp -o $(OBJFOLDR)/business.o $(CXXFLAGS)

$(OBJFOLDR)/cash.o: cash.cpp
	$(CPPTOOL) -c cash.cpp -o $(OBJFOLDR)/cash.o $(CXXFLAGS)

$(OBJFOLDR)/charges.o: charges.cpp
	$(CPPTOOL) -c charges.cpp -o $(OBJFOLDR)/charges.o $(CXXFLAGS)

$(OBJFOLDR)/chart.o: chart.cpp
	$(CPPTOOL) -c chart.cpp -o $(OBJFOLDR)/chart.o $(CXXFLAGS)

$(OBJFOLDR)/cheque.o: cheque.cpp
	$(CPPTOOL) -c cheque.cpp -o $(OBJFOLDR)/cheque.o $(CXXFLAGS)

$(OBJFOLDR)/contract.o: contract.cpp
	$(CPPTOOL) -c contract.cpp -o $(OBJFOLDR)/contract.o $(CXXFLAGS)

$(OBJFOLDR)/cost.o: cost.cpp
	$(CPPTOOL) -c cost.cpp -o $(OBJFOLDR)/cost.o $(CXXFLAGS)

$(OBJFOLDR)/country.o: country.cpp
	$(CPPTOOL) -c country.cpp -o $(OBJFOLDR)/country.o $(CXXFLAGS)

$(OBJFOLDR)/coupon.o: coupon.cpp
	$(CPPTOOL) -c coupon.cpp -o $(OBJFOLDR)/coupon.o $(CXXFLAGS)

$(OBJFOLDR)/currency.o: currency.cpp
	$(CPPTOOL) -c currency.cpp -o $(OBJFOLDR)/currency.o $(CXXFLAGS)

$(OBJFOLDR)/customer.o: customer.cpp
	$(CPPTOOL) -c customer.cpp -o $(OBJFOLDR)/customer.o $(CXXFLAGS)

$(OBJFOLDR)/datetime.o: datetime.cpp
	$(CPPTOOL) -c datetime.cpp -o $(OBJFOLDR)/datetime.o $(CXXFLAGS)

$(OBJFOLDR)/department.o: department.cpp
	$(CPPTOOL) -c department.cpp -o $(OBJFOLDR)/department.o $(CXXFLAGS)

$(OBJFOLDR)/depot.o: depot.cpp
	$(CPPTOOL) -c depot.cpp -o $(OBJFOLDR)/depot.o $(CXXFLAGS)

$(OBJFOLDR)/depreciation.o: depreciation.cpp
	$(CPPTOOL) -c depreciation.cpp -o $(OBJFOLDR)/depreciation.o $(CXXFLAGS)

$(OBJFOLDR)/discount.o: discount.cpp
	$(CPPTOOL) -c discount.cpp -o $(OBJFOLDR)/discount.o $(CXXFLAGS)

$(OBJFOLDR)/distributor.o: distributor.cpp
	$(CPPTOOL) -c distributor.cpp -o $(OBJFOLDR)/distributor.o $(CXXFLAGS)

$(OBJFOLDR)/dividend.o: dividend.cpp
	$(CPPTOOL) -c dividend.cpp -o $(OBJFOLDR)/dividend.o $(CXXFLAGS)

$(OBJFOLDR)/employee.o: employee.cpp
	$(CPPTOOL) -c employee.cpp -o $(OBJFOLDR)/employee.o $(CXXFLAGS)

$(OBJFOLDR)/equity.o: equity.cpp
	$(CPPTOOL) -c equity.cpp -o $(OBJFOLDR)/equity.o $(CXXFLAGS)

$(OBJFOLDR)/expense.o: expense.cpp
	$(CPPTOOL) -c expense.cpp -o $(OBJFOLDR)/expense.o $(CXXFLAGS)

$(OBJFOLDR)/factory.o: factory.cpp
	$(CPPTOOL) -c factory.cpp -o $(OBJFOLDR)/factory.o $(CXXFLAGS)

$(OBJFOLDR)/fees.o: fees.cpp
	$(CPPTOOL) -c fees.cpp -o $(OBJFOLDR)/fees.o $(CXXFLAGS)

$(OBJFOLDR)/fiscal.o: fiscal.cpp
	$(CPPTOOL) -c fiscal.cpp -o $(OBJFOLDR)/fiscal.o $(CXXFLAGS)

$(OBJFOLDR)/government.o: government.cpp
	$(CPPTOOL) -c government.cpp -o $(OBJFOLDR)/government.o $(CXXFLAGS)

$(OBJFOLDR)/income.o: income.cpp
	$(CPPTOOL) -c income.cpp -o $(OBJFOLDR)/income.o $(CXXFLAGS)

$(OBJFOLDR)/interest.o: interest.cpp
	$(CPPTOOL) -c interest.cpp -o $(OBJFOLDR)/interest.o $(CXXFLAGS)

$(OBJFOLDR)/inventory.o: inventory.cpp
	$(CPPTOOL) -c inventory.cpp -o $(OBJFOLDR)/inventory.o $(CXXFLAGS)

$(OBJFOLDR)/invoice.o: invoice.cpp
	$(CPPTOOL) -c invoice.cpp -o $(OBJFOLDR)/invoice.o $(CXXFLAGS)

$(OBJFOLDR)/item.o: item.cpp
	$(CPPTOOL) -c item.cpp -o $(OBJFOLDR)/item.o $(CXXFLAGS)

$(OBJFOLDR)/ledger.o: ledger.cpp
	$(CPPTOOL) -c ledger.cpp -o $(OBJFOLDR)/ledger.o $(CXXFLAGS)

$(OBJFOLDR)/liability.o: liability.cpp
	$(CPPTOOL) -c liability.cpp -o $(OBJFOLDR)/liability.o $(CXXFLAGS)

$(OBJFOLDR)/loan.o: loan.cpp
	$(CPPTOOL) -c loan.cpp -o $(OBJFOLDR)/loan.o $(CXXFLAGS)

$(OBJFOLDR)/manufacturer.o: manufacturer.cpp
	$(CPPTOOL) -c manufacturer.cpp -o $(OBJFOLDR)/manufacturer.o $(CXXFLAGS)

$(OBJFOLDR)/milestone.o: milestone.cpp
	$(CPPTOOL) -c milestone.cpp -o $(OBJFOLDR)/milestone.o $(CXXFLAGS)

$(OBJFOLDR)/office.o: office.cpp
	$(CPPTOOL) -c office.cpp -o $(OBJFOLDR)/office.o $(CXXFLAGS)

$(OBJFOLDR)/order.o: order.cpp
	$(CPPTOOL) -c order.cpp -o $(OBJFOLDR)/order.o $(CXXFLAGS)

$(OBJFOLDR)/party.o: party.cpp
	$(CPPTOOL) -c party.cpp -o $(OBJFOLDR)/party.o $(CXXFLAGS)

$(OBJFOLDR)/payable.o: payable.cpp
	$(CPPTOOL) -c payable.cpp -o $(OBJFOLDR)/payable.o $(CXXFLAGS)

$(OBJFOLDR)/payment.o: payment.cpp
	$(CPPTOOL) -c payment.cpp -o $(OBJFOLDR)/payment.o $(CXXFLAGS)

$(OBJFOLDR)/person.o: person.cpp
	$(CPPTOOL) -c person.cpp -o $(OBJFOLDR)/person.o $(CXXFLAGS)

$(OBJFOLDR)/price.o: price.cpp
	$(CPPTOOL) -c price.cpp -o $(OBJFOLDR)/price.o $(CXXFLAGS)

$(OBJFOLDR)/product.o: product.cpp
	$(CPPTOOL) -c product.cpp -o $(OBJFOLDR)/product.o $(CXXFLAGS)

$(OBJFOLDR)/project.o: project.cpp
	$(CPPTOOL) -c project.cpp -o $(OBJFOLDR)/project.o $(CXXFLAGS)

$(OBJFOLDR)/purchase.o: purchase.cpp
	$(CPPTOOL) -c purchase.cpp -o $(OBJFOLDR)/purchase.o $(CXXFLAGS)

$(OBJFOLDR)/quote.o: quote.cpp
	$(CPPTOOL) -c quote.cpp -o $(OBJFOLDR)/quote.o $(CXXFLAGS)

$(OBJFOLDR)/receivable.o: receivable.cpp
	$(CPPTOOL) -c receivable.cpp -o $(OBJFOLDR)/receivable.o $(CXXFLAGS)

$(OBJFOLDR)/report.o: report.cpp
	$(CPPTOOL) -c report.cpp -o $(OBJFOLDR)/report.o $(CXXFLAGS)

$(OBJFOLDR)/retailer.o: retailer.cpp
	$(CPPTOOL) -c retailer.cpp -o $(OBJFOLDR)/retailer.o $(CXXFLAGS)

$(OBJFOLDR)/revenue.o: revenue.cpp
	$(CPPTOOL) -c revenue.cpp -o $(OBJFOLDR)/revenue.o $(CXXFLAGS)

$(OBJFOLDR)/role.o: role.cpp
	$(CPPTOOL) -c role.cpp -o $(OBJFOLDR)/role.o $(CXXFLAGS)

$(OBJFOLDR)/sale.o: sale.cpp
	$(CPPTOOL) -c sale.cpp -o $(OBJFOLDR)/sale.o $(CXXFLAGS)

$(OBJFOLDR)/service.o: service.cpp
	$(CPPTOOL) -c service.cpp -o $(OBJFOLDR)/service.o $(CXXFLAGS)

$(OBJFOLDR)/staff.o: staff.cpp
	$(CPPTOOL) -c staff.cpp -o $(OBJFOLDR)/staff.o $(CXXFLAGS)

$(OBJFOLDR)/store.o: store.cpp
	$(CPPTOOL) -c store.cpp -o $(OBJFOLDR)/store.o $(CXXFLAGS)

$(OBJFOLDR)/supplier.o: supplier.cpp
	$(CPPTOOL) -c supplier.cpp -o $(OBJFOLDR)/supplier.o $(CXXFLAGS)

$(OBJFOLDR)/task.o: task.cpp
	$(CPPTOOL) -c task.cpp -o $(OBJFOLDR)/task.o $(CXXFLAGS)

$(OBJFOLDR)/tax.o: tax.cpp
	$(CPPTOOL) -c tax.cpp -o $(OBJFOLDR)/tax.o $(CXXFLAGS)

$(OBJFOLDR)/trade.o: trade.cpp
	$(CPPTOOL) -c trade.cpp -o $(OBJFOLDR)/trade.o $(CXXFLAGS)

$(OBJFOLDR)/transaction.o: transaction.cpp
	$(CPPTOOL) -c transaction.cpp -o $(OBJFOLDR)/transaction.o $(CXXFLAGS)

$(OBJFOLDR)/transporter.o: transporter.cpp
	$(CPPTOOL) -c transporter.cpp -o $(OBJFOLDR)/transporter.o $(CXXFLAGS)

$(OBJFOLDR)/usage.o: usage.cpp
	$(CPPTOOL) -c usage.cpp -o $(OBJFOLDR)/usage.o $(CXXFLAGS)

$(OBJFOLDR)/vehicle.o: vehicle.cpp
	$(CPPTOOL) -c vehicle.cpp -o $(OBJFOLDR)/vehicle.o $(CXXFLAGS)

$(OBJFOLDR)/warehouse.o: warehouse.cpp
	$(CPPTOOL) -c warehouse.cpp -o $(OBJFOLDR)/warehouse.o $(CXXFLAGS)