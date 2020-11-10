// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/04/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "RecordSet.h"
#include <iomanip>
#include <fstream>
#include <iostream>

namespace sdds {
	RecordSet::RecordSet() // default constructor
	{
		record = nullptr;
		numOfRecord = 0u;
	};

	RecordSet::~RecordSet() // destructor
	{
		delete[] record;
		record = nullptr;
	};
	
	RecordSet::RecordSet(char* name) 
	{
		std::ifstream f(name);
		std::string str;
		record = nullptr;
		
		if (f.is_open())
		{
			while (!f.eof()) // count number of word util the end of file
			{
				getline(f, str, ' ');
				numOfRecord++;
			}

			f.clear();
			f.seekg(0); // back to the beginning of file
		
			record = new std::string[numOfRecord];
			
			for (size_t i = 0u; i < numOfRecord; i++) // record all arguments
			{
				std::getline(f, str, ' ');
				record[i] = str; 
			}
			f.close();
		}
	};
	
	RecordSet::RecordSet(const RecordSet& src) // copy constructor
	{
		record = nullptr;
		*this = src;
	};
	RecordSet& RecordSet::operator=(const RecordSet& src) // copy assignment
	{
		if (this != &src)
		{
			this->numOfRecord = src.numOfRecord;
			delete[] this->record;
			this->record = new std::string[numOfRecord];
			for (auto i = 0u; i < numOfRecord; i++)
			{
				this->record[i] = src.record[i];
			}
		}
        return *this;
	};

	RecordSet::RecordSet(RecordSet&& src) // move constructor
	{
		record = nullptr;
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(RecordSet&& src) // move copy assignment
	{
		if (this != &src)
		{
			this->numOfRecord = src.numOfRecord;
			delete[] this->record;
			this->record = src.record;

			src.record = nullptr;
			src.numOfRecord = 0u;
		}
		return *this;
	}

	size_t RecordSet::size() const
	{
		return numOfRecord;
	};
	
	std::string RecordSet::getRecord(size_t index) const
	{
		return index < numOfRecord ? record[index] : "";
	};
}