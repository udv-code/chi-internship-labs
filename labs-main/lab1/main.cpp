#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "txt.hpp"

#define TIMEP(start, end) (std::chrono::duration_cast<std::chrono::nanoseconds>((end) - (begin)).count())
#define NOW std::chrono::high_resolution_clock::now()

#define LABEL_WIDTH 12
#define DURATION_WIDTH 9


int main(int argc, char* argv[])
{
	std::ofstream ofs("Lab1Output.txt");

	if (argc == 1)
	{
		std::cout << argv[0] << ": missing file \n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cout << argv[0] << ": too many arg\n";
		return 2;
	}

	auto begin = NOW;
	auto end = NOW;

	{
		begin = NOW;
		l1::Txt a;
		end = NOW;
		ofs << std::left << std::setw(LABEL_WIDTH) << "Def Const"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = NOW;
		l1::Txt b(argv[1]);
		end = NOW;
		ofs << std::left << std::setw(LABEL_WIDTH) << "Cust Const"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - b.size = " << b.size() << std::endl;

		begin = NOW;
		a = b;
		end = NOW;
		ofs << std::left << std::setw(LABEL_WIDTH) << "Cp Assig"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = NOW;
		a = std::move(b);
		end = NOW;
		ofs << std::left << std::setw(LABEL_WIDTH) << "Mv Assig"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = NOW;
		l1::Txt c = a;
		end = NOW;
		ofs << std::left<< std::setw(LABEL_WIDTH) << "Cp Const"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - c.size = " << c.size() << std::endl;

		begin = NOW;
		l1::Txt d = std::move(a);
		end = NOW;
		ofs << std::left << std::setw(LABEL_WIDTH) << "Mv Const"
			<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
			<< " - d.size = " << d.size() << std::endl;

		begin = NOW;
	}
	end = NOW;
	ofs << std::left << std::setw(LABEL_WIDTH) << "Dest"
		<< std::setw(DURATION_WIDTH) << TIMEP(begin, end) << " nanoseconds"
		<< std::endl;

	ofs.close();
	return 0;
}