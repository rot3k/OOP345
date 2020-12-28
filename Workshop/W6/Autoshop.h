// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles; // a vector that store all the vehicles available at this autoshop.
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); ++i)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
}

#endif
