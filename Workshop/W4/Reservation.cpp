// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Reservation.h"
#include <algorithm>
#include <iomanip>

namespace sdds {
	
	Reservation::Reservation() : m_id{ "" }, m_name{ "" }, m_email{ "" }, m_numOfPeople{ 0 }, m_day{ 0 }, m_hour{ 0 } {}
	
	Reservation::Reservation(const std::string& res)
	{
		std::string temp = res;
		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end()); // remove all leading and trailing spaces

		this->m_id = temp.substr(0, temp.find(':')); // id
		temp.erase(0, temp.find(':') + 1);

		this->m_name = temp.substr(0, temp.find(',')); // name
		temp.erase(0, temp.find(',') + 1);

		this->m_email = temp.substr(0, temp.find(',')); // email
		temp.erase(0, temp.find(',') + 1);

		this->m_numOfPeople = std::stoi(temp.substr(0, temp.find(','))); // number of people
		temp.erase(0, temp.find(',') + 1);

		this->m_day = std::stoi(temp.substr(0, temp.find(','))); // day
		temp.erase(0, temp.find(',') + 1);

		this->m_hour = std::stoi(temp); // hour
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation " << res.m_id << ": ";
		os <<  std::right << std::setw(10) << res.m_name << "  ";
		os << std::left << std::setw(20) << "<" + res.m_email + ">" << "    ";
		os << ((res.m_hour >= 6 && res.m_hour <= 9) ? "Breakfast" : (res.m_hour >= 11 && res.m_hour <= 15) ? "Lunch" : (res.m_hour >= 17 && res.m_hour <= 21) ? "Dinner" : "Drinks");
		os << " on day " << res.m_day << " ";
		os << "@ " << res.m_hour << ":00 ";
		os << "for " << res.m_numOfPeople << " " << "people." << std::endl;
		return os;
	}
}