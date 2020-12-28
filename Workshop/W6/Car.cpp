// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/08/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Car.h"

namespace sdds {
	Car::Car() : c_maker{ "" }, c_condition{ "" }, c_tSpeed{ 0.0 }{}
	
	std::string Car::removeSpace(std::string& str) // any space at the beginning/end of each field should be removed.
	{
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
	
	Car::Car(std::istream& is) // a custom constructor that receives an object of type std::istream& as parameter.
	{
		std::string temp;
		getline(is, temp, ','); // tag
		
		getline(is, temp, ','); // maker
		c_maker = removeSpace(temp); 

		getline(is, temp, ','); // condition
		removeSpace(temp);
		if (temp == "n" || temp == "") // the token representing the condition the car is empty (no characters or only blanks)
		{
			c_condition = "new";
		}
		else if (temp == "u")
		{
			c_condition = "used";
		}
		else if (temp == "b")
		{
			c_condition = "broken";
		}
		else
		{
			throw std::string("Invalid record!");
		}

		getline(is, temp, ','); // top speed
		try
		{
			c_tSpeed = std::stod(temp); 
		}
		catch (...)
		{
			throw std::string("Invalid record!");
		}
	}
	std::string Car::condition() const
	{
		return this->c_condition;
	}

	double Car::topSpeed() const
	{
		return this->c_tSpeed;
	}
	
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << this->c_maker << " | " ;
		out << std::left << std::setw(6) << this->condition() << " | ";
		out	<< std::right << std::setw(6) << std::fixed << std::setprecision(2) << this->topSpeed() << " |" ;
	}
}