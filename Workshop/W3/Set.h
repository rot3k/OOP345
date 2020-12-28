// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/11/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template<typename T, unsigned N> 
	class Set
	{
		T a[N]{};
		unsigned num{ 0u };
	 
	public:
		size_t size() const // return current number of elements
		{
			return num;
		}
		
		const T& operator[](size_t idx) const // return the element at index
		{
			return a[idx];
		}
		
		void operator+=(const T& item) // check capacity of collection
		{
			if (N > num)
			{
				a[num++] = item;
			}
		}
	};
}

#endif// !SDDS_SET_H
