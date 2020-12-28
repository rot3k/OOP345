// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif
