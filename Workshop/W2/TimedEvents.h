// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/04/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include<chrono>
#include<string>

namespace sdds {
	const int MAX_NUM_RECORD = 7; // predefined the maximum number of objects

	class TimedEvents
	{
		int numOfRecord{ 0 }; // number of record
		std::chrono::steady_clock::time_point timeStart{}; // start time
		std::chrono::steady_clock::time_point timeEnd{}; // end time
		struct
		{
			std::string m_enventName;
			std::string m_unitofTime;
			std::chrono::steady_clock::duration m_duration;
		} record[MAX_NUM_RECORD]{};

	public:
		TimedEvents(); // default constructor
		void startClock(); // starts the timer
		void stopClock(); // stops the timer
		void recordEvent(const char* eventName); // receives name of the event. 
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te); // friend insertion operator
	};
}
#endif // !SDDS_TIMEDEVENTS_H

