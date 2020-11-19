// Copyright (c) 2020 udv. All rights reserved.

#ifndef CHI_INTERNSHIP_LABS_LIST
#define CHI_INTERNSHIP_LABS_LIST

namespace l2 {
	template<typename T, size_t s>
	class List {
		using size_type = size_t;
	public:
		List() : mData {}, mSize { 0 } {};
		List(std::initializer_list<T> list);
		explicit List(T value);

		[[nodiscard]] constexpr size_type capacity() const noexcept { return s; }
		[[nodiscard]] size_type size() const noexcept { return mSize; }

		[[nodiscard]] T &operator[](size_type index) noexcept { return mData[index]; }
		[[nodiscard]] const T &operator[](size_type index) const noexcept { return mData[index]; }

		const T *data() const noexcept { return mData; }
		T *data() noexcept { return mData; }

		List& operator+=(T value);

	private:
		T mData[s];
		size_t mSize;
	};

	template <typename T>
	class List<T, 0> {
		using size_type = size_t;
	public:
		List() = default;
		[[nodiscard]] constexpr size_type capacity() const noexcept { return 0; }
		[[nodiscard]] constexpr size_type size() const noexcept { return 0; }
	};
}

#endif //CHI_INTERNSHIP_LABS_LIST

// Definitions
#include "inl/list.inl"