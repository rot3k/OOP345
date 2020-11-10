// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/04/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <string>

namespace sdds {
	class RecordSet
	{
		std::string* record{ 0 };
		size_t numOfRecord{ 0 };
	public:
		RecordSet(); // default constructor
		~RecordSet(); // destructor
		RecordSet(char* name);
		RecordSet(const RecordSet& src); // copy constructor
		RecordSet& operator=(const RecordSet& src); // copy assignment
		size_t size() const;
		std::string getRecord(size_t index) const;
		RecordSet(RecordSet&& src); // move constructor
		RecordSet& operator=(RecordSet&& src); // move copy assignment
	};
}

#endif// !SDDS_RECORDSET_H