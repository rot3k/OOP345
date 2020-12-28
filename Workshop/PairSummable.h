// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/11/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include<iostream>
#include<string>
#include"Pair.h"

namespace sdds {

	template<typename K, typename V>
	class PairSummable : public Pair<K, V> // base class of PariSummable
	{
		static V initValue; 
		static size_t mWidth;

	public:
		PairSummable() {} // default constructor
		PairSummable(const K& key, const V& value = initValue) : Pair<K, V>(key, value) // call base class. update field width
		{
			if (mWidth < key.size())
			{
				mWidth = key.size();
			}
		}

		PairSummable& operator+=(const PairSummable& P) // to add the value to current object if both have same key
		{
			
			if (this->key() == P.key())
			{
				PairSummable ps(this->key(), this->value() + P.value());
				*this = ps;
			}
			return *this;
		}

		void display(std::ostream& os)const // display followed the form
		{
			os << std::left << std::setw(mWidth);
			Pair<K, V>:: display(os);
			os << std::right;
		}
	};

	template <typename K, typename V>
	size_t PairSummable<K, V>::mWidth = 0; // initialize mWidth 
	
	template<>
	std::string PairSummable<std::string, std::string>::initValue = "";  // initialize initValue
	template<>
	int PairSummable<std::string, int>::initValue = 0; // // initialize initValue 
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& P) // concatenate the values
	{
		
		if (this->key() == P.key())
		{
			if (this->value() == "")
			{
				PairSummable<std::string, std::string> ps(this->key(), this->value() + P.value());
				*this = ps;
			}
			else
			{
				PairSummable<std::string, std::string> ps(this->key(), this->value() + ", " + P.value());
				*this = ps;
			}
		}
			return *this;
	}
}


#endif // !SDDS_PAIRSUMMABLE_H 