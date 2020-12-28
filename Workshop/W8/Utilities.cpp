// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/21/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		//This function compares the elements in the two received lists for common product codes and builds the user-friendly list from the matching pairs.
		for (auto i = 0u; i < desc.size(); ++i)
		{
			for (auto j = 0u; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code)
				{
					//For each successful comparison, your function allocates dynamic memory of Product type using that description and the price
					Product* p = new Product(desc[i].desc, price[j].price);
					// Your function then validates the Product object
					p->validate(); 
					//adds it to its list
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (auto i = 0u; i < desc.size(); ++i)
		{
			for (auto j = 0u; j < price.size(); ++j)
			{
				if (desc[i].code == price[j].code)
				{
					//For each successful comparison, your function allocates dynamic memory of Product type using that description and the price
					unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					// Your function then validates the Product object
					p->validate();
					//adds it to its list
					priceList += std::move(p);
				}
			}
		}

		return priceList;
	}
}
