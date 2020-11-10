// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/04/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "TimedEvents.h"
#include <iomanip>

namespace sdds {

	TimedEvents::TimedEvents()
	{
		numOfRecord = 0;
		timeStart = {};
		timeEnd = {};
	};
		
	void TimedEvents::startClock()
	{
		timeStart = std::chrono::steady_clock::now();
	};
	
	void TimedEvents::stopClock()
	{
		timeEnd = std::chrono::steady_clock::now();
	};

	void TimedEvents::recordEvent(const char* eventName)
	{
		this->record[numOfRecord].m_enventName = eventName;
		this->record[numOfRecord].m_unitofTime = "nanoseconds";
		this->record[numOfRecord].m_duration = 
			std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart);
		numOfRecord++;
	};
	std::ostream& operator<<(std::ostream& os, const TimedEvents& te)
	{
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < te.numOfRecord; i++)
		{
			os << std::setw(20) << std::left << te.record[i].m_enventName;
			os << std::setw(12) << std::right << te.record[i].m_duration.count();
			os << ' ' << te.record->m_unitofTime << "\n";
			
		}
		os << "--------------------------\n";
		return os;
	};




}