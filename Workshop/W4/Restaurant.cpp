// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Restaurant.h"
#include <iomanip>

namespace sdds {

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) // constructor, store copies of all reservations
	{
		this->reservation = new Reservation[cnt];
		this->numOfReserv = cnt;

		for (auto i = 0u; i < this->numOfReserv; i++)
		{
			this->reservation[i] = *reservations[i];
		}
	}

	Restaurant::~Restaurant() // destructor
	{
		if (this->numOfReserv != 0)
		{
			delete[] this->reservation;
		}
		this->reservation = nullptr;
	}
	
	Restaurant::Restaurant(const Restaurant& src) // copy constructor
	{
		reservation = nullptr;
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept// move constructor
	{
		reservation = nullptr;
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) // copy assignment operator 
	{
		if (this != &src)
		{
			this->numOfReserv = src.numOfReserv;
			delete[] this->reservation;
			this->reservation = new Reservation[numOfReserv];
			for (auto i = 0u; i < numOfReserv; i++)
			{
				this->reservation[i] = src.reservation[i];
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept// move assignment operator
	{
		if (this != &src)
		{
			this->numOfReserv = src.numOfReserv;
			delete[] this->reservation;
			this->reservation = src.reservation;

			src.reservation = nullptr;
			src.numOfReserv = 0u;
		}
		return *this;
	}

	size_t Restaurant::size() const
	{
		return this->numOfReserv;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& rest) // friend helper
	{
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		if (rest.size() == 0)
		{
			os << "The object is empty!" << std::endl;
		}
		else
		{
			for (auto i = 0u; i < rest.numOfReserv; i++)
			{
				os << rest.reservation[i];
			}
		}

		os << "--------------------------" << std::endl;
		return os;
	}
}