// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_SALE
#define CHI_INTERNSHIP_LABS_SALE

#include <vector>

#include "product.hpp"

namespace sict {
	class Sale {
	public:
		explicit Sale(const char* filename);
		~Sale();
		void display(std::ostream& os);
	private:
		std::vector<sict::iProduct*> mProducts;
	};
}

#endif //CHI_INTERNSHIP_LABS_SALE

// Definitions
#include "inl/sale.inl"