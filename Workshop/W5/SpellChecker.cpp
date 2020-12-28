// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <fstream>
#include <algorithm>
#include "SpellChecker.h"


namespace sdds {

	SpellChecker::SpellChecker(const char* filename) // If the file exists, this constructor loads its contents. If the file is missing, this constructor throws an exception of type const char*, with the message Bad file name!
	{
		std::ifstream file(filename);
		size_t count = 0u;
		if (!file)
		{
			throw ("Bad file name!");
		}
		
		do
		{
			if (file)
			{
				file >> this->m_badWords[count] >> this->m_goodWords[count];
				count++;
			}
		} while (file);
		file.close();
	}
	
	void SpellChecker::operator()(std::string& text) const // earches text and replaces any misspelled word with the correct version
	{
		for (auto i = 0u; i < 5; ++i)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(this->m_badWords[i]), this->m_badWords[i].length(), this->m_goodWords[i]);
			}
		}
	}
}