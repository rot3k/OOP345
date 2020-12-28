// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/11/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include<iostream>
#include<string>
#include"Set.h"

namespace sdds {
	template<typename T, unsigned N>
	class SetSummable :public Set<T, N>
	{
	public:
		T accumulate(const std::string& filter) const // accumulates all the elements that equal filter
		{
			T initAccumaltor(filter);

			for (size_t i = 0u; i < this->size(); i++)
			{
				if ((*this)[i].key() == filter)
				{
					initAccumaltor += (*this)[i];
				}
			}
			return initAccumaltor;
		}
	};
}

#endif // !SDDS_SETSUMMABLE_H 
