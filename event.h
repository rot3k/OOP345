// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 09/26/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned long g_sysClock; // positive integer between 0 and 86400, declaration

namespace sdds {
	
	class Event {

		char* event_desc; // including null-terminated string up to 128
		unsigned long event_time; // positive integer between 0 and 86400

	public:

		Event();
		~Event();
		Event(const Event& src); // copy constructor
		Event& operator=(const Event& src); // copy assignment operator
		void display() const;
		void setDescription(const char* e_desc);

	};
}
#endif // !SDDS_EVENT_H
