// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include<iostream>
#include<string>
#include "Reservation.h"

namespace sdds {
	class Restaurant
	{
		Reservation* reservation{ nullptr }; // dynamically allocated array
		size_t numOfReserv{ 0 };

	public:
		
		Restaurant(Reservation* reservations[], size_t cnt); //constructor
		~Restaurant(); // destructor
		Restaurant(const Restaurant& src); // copy constructor
		Restaurant(Restaurant&& src) noexcept; // move constructor
		Restaurant& operator=(const Restaurant& src); // copy assignment operator
		Restaurant& operator=(Restaurant&& src) noexcept; // move assignment operator
		size_t size() const; // return numOfReserv
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest); // friend helper
	};
}
#endif // !SDDS_RESTAURANT_H
