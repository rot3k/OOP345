// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include<iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
		const Reservation** conReservation{ nullptr }; // dynamic array of pointers 
		size_t cNumOfReserv{ 0 };

	public:
		ConfirmationSender(); // default constructor
		~ConfirmationSender(); // destructor
		ConfirmationSender(const ConfirmationSender& src); // copy constructor
		ConfirmationSender(ConfirmationSender&& src) noexcept; // move constructor
		ConfirmationSender& operator=(const ConfirmationSender& src); // copy assignment operator
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept; // move assignment operator
		ConfirmationSender& operator+=(const Reservation& res); // add
		ConfirmationSender& operator-=(const Reservation& res); // remove
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& conSend); //friend helper
	};
}

#endif // !SDDS_CONFERMATIONSENDER_H
