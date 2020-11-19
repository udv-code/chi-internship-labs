// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_LIST_INL
#define CHI_INTERNSHIP_LABS_LIST_INL

#ifndef CHI_INTERNSHIP_LABS_LIST
#include "list.hpp"
#endif

namespace l2
{
	template<typename T, size_t s>
	List<T, s>::List(std::initializer_list<T> list) : List{}
	{
		std::copy(list.begin(), list.end(), mData);
		mSize = list.size();
	}

	template<typename T, size_t s>
	List<T, s>::List(T value) : List{}
	{
		std::fill(mData, mData + s, value);
		mSize = s;
	}

	template<typename T, size_t s>
	List <T, s>& List<T, s>::operator+=(T value)
	{
		if (mSize < capacity()) {
			mData[mSize++] = value;
		}
		return *this;
	}
}

#endif //CHI_INTERNSHIP_LABS_LIST_INL
