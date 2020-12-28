// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>

namespace sdds {
	class Movie {
		std::string mv_title;
		size_t mv_year;
		std::string mv_desc;
	public:
		Movie();
		void removeSpace(std::string& str); // remove all spaces from the beginningand end of any token in the string.
		const std::string& title() const;
		Movie(const std::string& strMovie);
		
		template<typename T>
		void fixSpelling(T spellChecker) // calls the overloaded operator() on the instance spellChecker, passing to it the book description.
		{
			spellChecker(this->mv_desc);
			spellChecker(this->mv_title);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& mv);
	};
}
#endif // !SDDS_MOVIE_H
