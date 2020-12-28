#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/21/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif