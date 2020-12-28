#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/21/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.

		//Your function receives the address of an object to be stored in the List container and moves the object into that container
		void operator += (T* rPtr)
		{
			list.push_back(*rPtr);
		}

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		void operator += (std::unique_ptr<T> sPtr)
		{
			list.push_back(std::move(*sPtr));
		}

		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif