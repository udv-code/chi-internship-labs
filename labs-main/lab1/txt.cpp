// Copyright (c) 2020 udv. All rights reserved.

#include "txt.hpp"

#include <fstream>
#include <algorithm>

namespace l1
{
	Txt::Txt() : mStrings{ nullptr }, mSize{ 0 }
	{
	}

	Txt::Txt(const std::string& filename) : Txt()
	{
		std::ifstream file;
		file.open(filename);

		if (!file.fail())
		{
			if (file.bad())
			{
				return;
			}

			mSize = countLines(file);
			mStrings = new std::string[mSize];

			size_type i = 0;
			std::string line;
			while (!file.eof())
			{
				line.clear();
				std::getline(file, line);
				mStrings[i++] = std::move(line);
			}
		}
		else
		{
			mSize = 0;
			mStrings = nullptr;
		}

		file.close();
	}

	Txt::~Txt()
	{
		delete[] mStrings;
	}

	Txt& Txt::operator=(const Txt::type& other)
	{
		if (&other == this)
		{
			return *this;
		}

		delete[] mStrings;

		mSize = other.mSize;
		mStrings = new std::string[mSize];
		std::copy(other.mStrings, other.mStrings + other.mSize,
				mStrings);

		return *this;
	}

	Txt& Txt::operator=(Txt::type&& other) noexcept
	{
		if (&other == this)
		{
			return *this;
		}

		delete[] mStrings;

		mSize = other.mSize;
		mStrings = other.mStrings;

		other.mSize = 0;
		other.mStrings = nullptr;

		return *this;
	}

	Txt::size_type Txt::countLines(std::ifstream& file)
	{
		if (file.bad())
		{
			return 0;
		}

		auto oldState = file.rdstate();
		file.clear();
		auto oldPos = file.tellg();
		file.seekg(0);

		auto lineCount = std::count(std::istreambuf_iterator<char>(file),
				std::istreambuf_iterator<char>(), '\n');
		++lineCount;
		file.unget();
		if (file.get() != '\n')
		{
			++lineCount;
		}

		file.clear();
		file.seekg(oldPos);
		file.setstate(oldState);

		return lineCount;
	}
}