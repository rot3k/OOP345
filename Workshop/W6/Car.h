// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"


namespace sdds
{
	class Car : public Vehicle 
	{
		std::string c_maker;
		std::string c_condition; 
		double c_tSpeed;
	public:
		Car(); // default Constructor
		std::string removeSpace(std::string& str);
		Car(std::istream& is); 
		std::string condition() const; 
		double topSpeed() const;
		void display(std::ostream& out) const; 
	};
}

#endif
