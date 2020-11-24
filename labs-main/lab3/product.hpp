// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_PRODUCT
#define CHI_INTERNSHIP_LABS_PRODUCT

#include <ostream>

extern int FW;

#define HT 'H'
#define PT 'P'

#define HT_C 0.13
#define PT_C 0.08

#define WITH_TAX(x) (1 - x)

namespace sict
{
	class iProduct
	{
	public:
		iProduct(int id, double price, char tax) : mId { id }, mPrice { price }, mTax { tax } {};
		~iProduct() = default;

		[[nodiscard]] double price() const {
			if (mTax == HT)
			{
				return mPrice * WITH_TAX(HT_C);
			} else if (mTax == PT){
				return mPrice * WITH_TAX(PT_C);
			} else {
				return mPrice;
			}
		};
		void display(std::ostream& os) const;

		static iProduct* readRecord(std::ifstream& file);
	public:
		friend std::ostream& operator<<(std::ostream& os, const iProduct& product)
		{
			product.display(os);
			return os;
		}

	private:
		int mId;
		double mPrice;
		char mTax;
	};
}

#endif //CHI_INTERNSHIP_LABS_PRODUCT

// Definitions
#include "inl/product.inl"