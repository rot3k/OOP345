// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/15/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<list>

namespace sdds {
	struct Song {
		std::string s_artist{ "" };
		std::string s_title{ "" };
		std::string s_album{ "" };
		double m_price{ 0.0 };
		size_t s_year{ 0u };
		size_t s_length{ 0u };
	};

	class SongCollection {
		std::vector<Song> s_song;
	public:
		SongCollection(const char* filename); // a custom constructor that receives as a parameter the name of the file
		void display(std::ostream& out) const;
		std::string removeSpace(std::string& str); // remove space
		void sort(std::string value);
		void cleanAlbum();
		bool inCollection(const std::string artist) const;
		std::list<Song> getSongsForArtist(const std::string artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong); //free helper
}

#endif // !SDDS_SONGCOLLECTION_H

