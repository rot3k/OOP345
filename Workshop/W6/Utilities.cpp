// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <fstream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* vehicle{ nullptr };
		std::string temp;
		char type{ '\0' };
		
		getline(in, temp);
		std::stringstream strings(temp);
		strings >> type;

		if (!temp.empty()) //If the first non-blank character is not c, C, r, or R this function should generate an exception, informing the client that this record contains information about an unknown vehicle.
		{
			if (type == 'c' || type == 'C')
			{
				vehicle = new Car(strings);
			}
			else if (type == 'r' || type == 'R')
			{
				vehicle = new Racecar(strings);
			}
			else
			{
				throw type;
			}
		}
		else
		{
			vehicle = nullptr; // If there is no more information to be extracted from the stream, this function should return nullptr.
		}
		return vehicle;
	} 
}