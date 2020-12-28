// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	Movie::Movie() : mv_title{""}, mv_year{0}, mv_desc{ "" } {}

	void Movie::removeSpace(std::string& str)
	{
		bool sp = true;
		while (sp)
		{
			if (str[0] == ' ')
			{
				str.erase(0, 1);
			}
			else if (str[str.length() - 1] == ' ')
			{
				str.erase(str.length() - 1, str.length());
			}
			else
			{
				sp = false;
			}
		}
	}
	
	const std::string& Movie::title() const
	{
		return mv_title;
	}
	
	Movie::Movie(const std::string& strMovie)
	{
		std::string temp = strMovie;
		
		this->mv_title = temp.substr(0, temp.find(',')); // title
		this->removeSpace(this->mv_title);
		temp.erase(0, temp.find(',') + 1);

		this->mv_year = std::stoi(temp.substr(0, temp.find(','))); // year
		temp.erase(0, temp.find(',') + 1);

		this->mv_desc = temp; // description
		this->removeSpace(this->mv_desc);
	}
	
	std::ostream &operator<<(std::ostream& os, const Movie& mv)
	{
		os << std::setw(40) << mv.mv_title << " | ";
		os << std::setw(4) << mv.mv_year << " | ";
		os << mv.mv_desc << std::endl;
		return os;
	}
}

