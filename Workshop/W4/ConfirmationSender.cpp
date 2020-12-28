// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/18/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "ConfirmationSender.h"
#include <iomanip>


namespace sdds {
	ConfirmationSender::ConfirmationSender() : conReservation{ nullptr }, cNumOfReserv{0}{} // defaut constructor
	
	ConfirmationSender::~ConfirmationSender() // destructor
	{
		delete[] this->conReservation;
		this->conReservation = nullptr;
	}
	
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) // copy constructor
	{
		conReservation = nullptr;
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept // move constructor
	{
		conReservation = nullptr;
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) // copy assignment operator
	{
		if (this != &src)
		{
			this->cNumOfReserv = src.cNumOfReserv;
			delete[] conReservation;
			this->conReservation = new const Reservation *[src.cNumOfReserv];
			for (auto i = 0u; i < src.cNumOfReserv; i++)
			{
				this->conReservation[i] = src.conReservation[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept // move assignment operator
	{
		if (this != &src)
		{
			this->cNumOfReserv = src.cNumOfReserv;
			delete[] this->conReservation;
			this->conReservation = src.conReservation;

			src.conReservation = nullptr;
			src.cNumOfReserv = 0u;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) // add the address of the reservation res to the array.
	{
		bool equal = false;

		for (auto i = 0u; i < cNumOfReserv; i++)
		{
			if (conReservation[i] == &res)
			{
				equal = true;
			}
		}

		if (equal == false)
		{
			const Reservation** temp = nullptr;
			temp = new const Reservation *[cNumOfReserv + 1];
			for (auto i = 0u; i < cNumOfReserv; i++)
			{
				temp[i] = conReservation[i];
			}
			temp[cNumOfReserv] = &res;
			
			cNumOfReserv++;
			delete[] conReservation;
			conReservation = temp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) // remove the address of the reservation res from the array.
	{
		bool equal = false;
		size_t flag = -1;
		
		for (auto i = 0u; i < cNumOfReserv; i++)
		{
			if (conReservation[i] == &res)
			{
				equal = true;
				flag = i;
			}
		}

		if (equal == true)
		{
			const Reservation** temp = nullptr;
			temp = new const Reservation * [cNumOfReserv - 1];
			for (auto i = 0u; i < cNumOfReserv - 1u; i++)
			{
				if (i < flag)
				{
					temp[i] = conReservation[i];
				}
				else
				{
					temp[i] = conReservation[i + 1];
				}
			}
			cNumOfReserv--;
			delete[] conReservation;
			conReservation = temp;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& conSend) // friend helper
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (conSend.cNumOfReserv == 0)
		{
			os << "The object is empty!" << std::endl;
		}
		else
		{
			for (auto i = 0u; i < conSend.cNumOfReserv; i++)
			{
				os << *conSend.conReservation[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;	
	}
}