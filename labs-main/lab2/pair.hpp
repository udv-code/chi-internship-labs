// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_PAIR
#define CHI_INTERNSHIP_LABS_PAIR

namespace l2 {
	template <typename K, typename V>
	class Pair {
	public:
		Pair() : mKey {}, mValue {} {}
		Pair(const K& key, const V& value) : mKey { key }, mValue { value } {}

		const K& getKey() { return mKey; }
		const V& getValue() { return mValue; }
	private:
		K mKey;
		V mValue;
	};
}

// Definitions
#include "inl/pair.inl"

#endif //CHI_INTERNSHIP_LABS_PAIR
