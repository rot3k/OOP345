// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 09/26/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "event.h"

unsigned long g_sysClock; // positive integer between 0 and 86400, definition

namespace sdds {

	Event::Event() // constructor
	{
		event_desc = nullptr ; // empty state
		event_time = 0u; // empty state
	}
	
	Event::~Event() // destructor
	{
		delete[] event_desc;
		event_desc = nullptr;
	}

	Event::Event(const Event& src) // copy constructor
	{
		event_desc = nullptr;
		*this = src;

	}

	Event& Event::operator=(const Event& src) // copy assignment operator
	{
		if (this != &src)
		{
			delete[] event_desc;

			if (src.event_desc != nullptr)
			{
				event_desc = new char[strlen(src.event_desc) + 1];
				strcpy(event_desc, src.event_desc);
			}
			else
			{
				event_desc = nullptr;
			}
			event_time = src.event_time;
		}

		return *this;
	}



	void Event::display() const
	{
		static unsigned counter{ 1u }; // remains in memory for the lifetime, initialization
		unsigned hh{ 0u };
		unsigned mm{ 0u };
		unsigned ss{ 0u };

		hh = event_time / 3600;
		mm = (event_time % 3600) / 60;
		ss = (event_time % 3600) % 60;

		std::cout.width(3);
		std::cout.fill(' ');
		std::cout << counter << ". ";
		counter++;
		
		if (event_desc == nullptr)
		{
			std::cout << "[ No Event ]" << '\n';
		}
		else
		{
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << hh << ":";

			std::cout.width(2);
			std::cout.fill('0');
			std::cout << mm << ":";

			std::cout.width(2);
			std::cout.fill('0');
			std::cout << ss << " -> " << event_desc << '\n';		
		}

	}
	void Event::setDescription(const char* e_desc)
	{
		if (e_desc == nullptr || e_desc[0] == '\0')
		{
			*this = Event();
		}
		else
		{
			delete[] event_desc;
			
			event_desc = new char[strlen(e_desc) + 1];
			strcpy(event_desc , e_desc);
			event_time = ::g_sysClock;
		}
	}
}