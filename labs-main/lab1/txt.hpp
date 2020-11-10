// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LAB1_TXT
#define CHI_INTERNSHIP_LAB1_TXT

#include <string>
#include <utility>

namespace l1 {
	class Txt {
		using type = Txt;
		using size_type = int32_t;
	public:
		Txt();
		Txt(const std::string& filename);
		Txt(const type& other) : Txt() {*this = other; };
		Txt(type&& other) noexcept : Txt() { *this = std::move(other); }

		~Txt();
	public:
		Txt& operator=(const type& other);
		Txt& operator=(type&& other)  noexcept;
	public:
		[[nodiscard]] size_type size() const { return mSize; }
	private:
		static size_type countLines(std::ifstream& file);
	private:
		std::string* mStrings;
		size_type mSize;
	};
}

#endif //CHI_INTERNSHIP_LAB1_TXT
