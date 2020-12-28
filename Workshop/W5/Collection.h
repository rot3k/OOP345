// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 10/28/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>

namespace sdds {
	template<typename T>
	class Collection
	{
		std::string c_name{ "" }; 
		T* c_items{ nullptr }; // dynamically allocated array of objects of type T
		size_t c_size{ 0u }; // the size of the array
		void(*observer)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(std::string name) : c_name{ name }, c_items{ nullptr }, c_size{ 0 }, observer{ nullptr } {} // default constructor
		~Collection() // destructor
		{
			delete[] c_items;
			c_items = nullptr;
		}

		Collection(const Collection& src) = delete;

		Collection& operator=(const Collection& src) = delete;

		const std::string& name() const
		{
			return c_name;
		}

		size_t size() const
		{
			return c_size;
		}

		void setObserver(void (*observer)(const Collection<T> &, const T&)) // stores the address of the callback function (observer) into an attribute. 
		{
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool equal = false;

			for (auto i = 0u; i < this->c_size; i++)
			{
				if (item.title() == this->c_items[i].title()) // if the collection doesn't contain an item with the same title (type T has a member function called title() that returns the title of the item)
				{
					equal = true;
				}
			}

			if (equal == false) // If the item is not yet in the collection, this function:
			{
				T* temp = new T[this->c_size + 1];
				for (auto i = 0u; i < this->c_size; ++i)
				{
					temp[i] = this->c_items[i];
				}
				temp[this->c_size] = item;
				delete[] this->c_items;
				this->c_items = nullptr;
				this->c_items = new T[++this->c_size];

				for (auto i = 0u; i < this->c_size; ++i)
				{
					this->c_items[i] = temp[i];
				}
				delete[] temp;
				temp = nullptr;

				if (this->observer != nullptr) //This function is called when an item is added to the collection.
				{
					this->observer(*this, item);
				}
			}
			return *this;
		}

		
		T& operator[](size_t idx) const
		{
			if (this->c_size <= idx) // if the index is out of range, this function throws an exception 
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->c_size) + "] items.");
			}
			else
			{
				return this->c_items[idx];
			}
		}

		T* operator[](std::string title) const // returns the address of the item with the title title
		{
			for (auto i = 0u; i < this->c_size; ++i)
			{
				if (this->c_items[i].title() == title)
				{
					return &this->c_items[i];
				}
			}
			return nullptr; // If no such item exists, this function returns nullptr
		}
	};

	template <typename T> // free helper
	std::ostream& operator<<(std::ostream& os, const Collection<T>& coll)
	{
		for (auto i = 0u; i < coll.size(); ++i)
		{
			os << coll[i];
		}
		return os;
	};

}

#endif // !SDDS_COLLECTION_H

