// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;
	public:
		Book();
		void removeSpace(std::string& str); // remove all spaces from the beginningand end of any token in the string.
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(); // can update
		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(this->m_desc);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& bk);
	};
}
#endif // !SDDS_BOOK_H
