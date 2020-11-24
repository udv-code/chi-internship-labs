// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_SALE_INL
#define CHI_INTERNSHIP_LABS_SALE_INL

#ifndef CHI_INTERNSHIP_LABS_SALE
#include "../sale.hpp"
#endif

#include <fstream>
#include "../sale.hpp"


namespace sict
{
	Sale::Sale(const char* filename)
			: mProducts{}
	{
		mProducts.reserve(8);
		std::ifstream infile;
		infile.exceptions(std::ifstream::badbit);
		try {
			infile.open(filename);

			while (!infile.eof())
			{
				auto* product = iProduct::readRecord(infile);
				if (product)
				{
					mProducts.push_back(product);
				}
			}
		}
		catch (const std::ifstream::failure& e)
		{
			throw e;
		}

		infile.close();
	}

	void Sale::display(std::ostream& os)
	{
		os << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::setw(FW) << "Taxable" << '\n';
		double total = 0;
		for (const auto& product : mProducts)
		{
			product->display(os);
			total += product->price();
		}
		os << std::setw(FW) << "Total" << ' ' << std::setw(FW) << total;
	}

	Sale::~Sale()
	{
		for (auto p : mProducts) {
			delete p;
		}
	}
}

#endif //CHI_INTERNSHIP_LABS_SALE_INL
