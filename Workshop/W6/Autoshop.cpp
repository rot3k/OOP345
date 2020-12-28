// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) // adds the vehicle received as parameter into the m_vehicles vector.
	{
		this->m_vehicles.push_back(theVehicle);
		return* this;
	}
	
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}
	
	Autoshop::~Autoshop() // destructor
	{
		if (!this->m_vehicles.empty())
		{
			auto i = this->m_vehicles.begin();

			while (i != this->m_vehicles.end())
			{
				delete *i;
				*i = nullptr;
				i = this->m_vehicles.erase(i);
			}
		}
	}
}