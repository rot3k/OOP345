// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/11/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include<iostream>

namespace sdds {
	template<typename K, typename V>
	class Pair
	{
		K k;
		V v;

	public:
		Pair() {}; //default constructor
		
		Pair(const K& key, const V& value) : k(key), v(value) {}; // copies values into instance variables
		
		const K& key() const // return key of the pair
		{
			return k;
		}

		const V& value() const // return value of the pair
		{
			return v;
		}

		virtual void display(std::ostream& os) const //display key and value, modified for polymorphism
		{
			os << k << " : " << v << std::endl;
		}
	};
	
	template<typename K, typename V> // free helper,call display() on pair and insert it into os 
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}

#endif// !SDDS_PAIR_H
