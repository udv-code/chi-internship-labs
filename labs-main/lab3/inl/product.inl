// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_PRODUCT_INL
#define CHI_INTERNSHIP_LABS_PRODUCT_INL

#ifndef CHI_INTERNSHIP_LABS_PRODUCT
#include "../product.hpp"
#endif

#include <fstream>
#include <iomanip>

namespace sict
{
	void Product::display(std::ostream& os) const
	{
		os << std::setw(FW) << mId << ' '
		   << std::setw(FW) << std::fixed << std::setprecision(2) << price() << '\n';
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		std::string tax;
		if (mTax == PT)
		{
			tax = "PST";
		}
		if (mTax == HT)
		{
			tax = "HST";
		}

		os << std::setw(FW) << mId << ' '
		   << std::setw(FW) << std::fixed << std::setprecision(2) << price() << ' '
		   << tax << "\n";
	}

	iProduct* iProduct::readRecord(std::ifstream& file)
	{
		std::istringstream iss;
		std::string line;

		int id = -1;
		double price = -1;
		char taxable = -1;
		getline(file, line);
		iss.str(line);
		iss >> id >> price >> taxable;

		if (id == -1 || price == -1)
		{
			return nullptr;
		}

		if (taxable == -1)
		{
			return new Product{ id, price };
		}
		else
		{
			return new TaxableProduct{ id, price, taxable };
		}

	}
}

#endif //CHI_INTERNSHIP_LABS_PRODUCT_INL
