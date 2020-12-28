// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include<iostream>
#include<string>

namespace sdds {
	
	class Reservation
	{
		std::string m_id{ "" };
		std::string m_name{ "" };
		std::string m_email{ "" };
		std::size_t m_numOfPeople{ 0 };
		std::size_t m_day{ 0 };
		std::size_t m_hour{ 0 };
	
	public:
		Reservation(); // default constructor
		Reservation(const std::string& res); // constructor
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res); // friend heper
	};
}
#endif // !SDDS_RESERVATION_H 
