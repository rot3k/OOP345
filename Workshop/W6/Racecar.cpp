// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <fstream>
#include "Racecar.h"
namespace sdds {
	Racecar::Racecar() : m_booster{0.0}{}
	
	Racecar::Racecar(std::istream& in) : Car(in)//calls the constructor from Car.  extracts the last field from the stream containing the booster bonus
	{
		std::string temp;
		getline(in, temp);
		this->m_booster = std::stod(temp);
	}
	
	void Racecar::display(std::ostream& out) const // calls Car::display() to print the information about the car, and adds * at the end
	{
		Car::display(out);
		out << "*";
	}
	
	double Racecar::topSpeed() const // returns the top speed of the car, including any booster effects.
	{
		return Car::topSpeed() * (1.0 + this->m_booster);
	}
}