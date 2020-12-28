// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds {
	Book::Book() : m_author{ "" }, m_title{ "" }, m_country{ "" }, m_year{ 0 }, m_price{ 0 }, m_desc{ "" } {}
	void Book::removeSpace(std::string& str)
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
	
	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;
		
		this->m_author = temp.substr(0, temp.find(',')); // author
		this->removeSpace(this->m_author);
		temp.erase(0, temp.find(',') + 1);

		this->m_title = temp.substr(0, temp.find(',')); // title
		this->removeSpace(this->m_title);
		temp.erase(0, temp.find(',') + 1);

		this->m_country = temp.substr(0, temp.find(',')); // country
		this->removeSpace(this->m_country);
		temp.erase(0, temp.find(',') + 1);

		this->m_price = std::stod(temp.substr(0, temp.find(','))); // price
		temp.erase(0, temp.find(',') + 1);
		
		this->m_year = std::stoi(temp.substr(0, temp.find(','))); // year
		temp.erase(0, temp.find(',') + 1);

		this->m_desc = temp; // description
		this->removeSpace(this->m_desc);
		
	}
	
	const std::string& Book::title() const
	{
		return m_title;
	}
	
	const std::string& Book::country() const
	{
		return m_country;
	}
	
	const size_t& Book::year() const
	{
		return m_year;
	}
	
	double& Book::price()
	{
		return m_price;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		os << std::setw(20) << bk.m_author << " | ";
		os << std::setw(22) << bk.m_title << " | ";
		os << std::setw(5) << bk.m_country << " | ";
		os << std::setw(4) << bk.m_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << bk.m_price << " | ";
		os << bk.m_desc << std::endl;
		return os;
	}
}