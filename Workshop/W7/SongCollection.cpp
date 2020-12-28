// Name: Sungsoo Cho
// Email: scho81@myseneca.ca
// ID: 121182190
// Date: 11/15/2020
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<string>
#include<fstream>
#include<iomanip>
#include <algorithm>
#include <numeric>
#include"SongCollection.h"

namespace sdds {
	std::string SongCollection::removeSpace(std::string& str)
	{
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
	
	SongCollection::SongCollection(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "ERROR: Cannot open file [" + std::string(filename) + "].\n"; // If the filename is incorrect, this constructor should throw an exception.
		}
		while (file) // TITLE, ARTIST and ALBUM have exactly 25 characters
		{
			std::string temp;
			std::getline(file, temp);
			Song song;
			if (file)
			{
				removeSpace(song.s_title = temp.substr(0, 25));
				temp.erase(0, 25);
				removeSpace(song.s_artist = temp.substr(0, 25));
				temp.erase(0, 25);
				removeSpace(song.s_album = temp.substr(0, 25));
				temp.erase(0, 25);

				try
				{
					song.s_year = std::stoi(temp.substr(0, 5));
					temp.erase(0, 5);
				}
				catch (...)
				{
					song.s_year = 0u;
					temp.erase(0, 5);
				}
				try
				{
					song.s_length = std::stoi(temp.substr(0, 5));
					temp.erase(0, 5);
				}
				catch (...)
				{
					song.s_length = 0u;
					temp.erase(0, 5);
				}
				try
				{
					song.m_price = std::stod(temp.substr(0, 5));
				}
				catch (...)
				{
					song.m_price = 0.0;
				}
				this->s_song.push_back(song);
			}
		}
		file.close();
	}
	
	void SongCollection::display(std::ostream& out) const 
	{
		//print the content of the collection into the parameter (one song / line)
		std::for_each(this->s_song.begin(), this->s_song.end(), [&](const Song& songs) {out << songs << std::endl; });
		//display the playtime of the entire collection (the total playtime is the sum of the length attribute of all songs)
		size_t totalPlayTime = std::accumulate(this->s_song.begin(), this->s_song.end(), (size_t)0u, [&](size_t sum, const Song& songs) {return sum + songs.s_length; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		std::string total = "Total Listening Time: ";
		total += std::to_string(totalPlayTime / 3600) + ":" + std::to_string((totalPlayTime % 3600) / 60) + ":" + std::to_string(totalPlayTime % 60);
		out << "|" << std::right << std::setw(85) << total << std::right << " |\n";
	}

	void SongCollection::sort(const std::string value) //receives as a parameter the name of the field used to sort the collection of songs in ascending order. The parameter can have one of the values title, album, or length
	{
		if (value == "title")
		{
			std::sort(this->s_song.begin(), this->s_song.end(), [](const Song& a, const Song& b) {return a.s_title < b.s_title; });
		}
		else if (value == "album")
		{
			std::sort(this->s_song.begin(), this->s_song.end(), [](const Song& a, const Song& b) {return a.s_album < b.s_album; });
		}
		else if (value == "length")
		{
			std::sort(this->s_song.begin(), this->s_song.end(), [](const Song& a, const Song& b) {return a.s_length < b.s_length; });
		}
	}

	void SongCollection::cleanAlbum() //  removes the token [None] from the album field of the songs that do not have a valid album
	{
		std::transform(this->s_song.begin(), this->s_song.end(), this->s_song.begin(), [](Song& a)
			{
				if (a.s_album == "[None]")
				{
					a.s_album = "";
				}
				return a;
			});
	}

	bool SongCollection::inCollection(std::string artist) const // receives the name of an artist as a parameter, and returns true if the collection contains any song by that artist.
	{
		return std::any_of(this->s_song.begin(), this->s_song.end(), [&](const Song& a) {return a.s_artist == artist; });
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string artist) const // receives the name of an artist as a parameter, and returns the list of songs of that artist available in the collection
	{
		std::list<Song> song;
		std::copy_if(this->s_song.begin(), this->s_song.end(), std::back_inserter(song), [&](const Song& a) {return a.s_artist == artist; });
		return song;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) //| TITLE(20) | ARTIST(15) | ALBUM(20) | YEAR(6) | LENGTH | PRICE |
	{
		out << "| " << std::left << std::setw(20) << theSong.s_title;
		out << " | " << std::left << std::setw(15) << theSong.s_artist;
		out << " | " << std::left << std::setw(20) << theSong.s_album;
		out << " | " << std::right << std::setw(6) << (theSong.s_year > 0 ? std::to_string(theSong.s_year) : "");
		out << " | " << theSong.s_length / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.s_length % 60 << std::setfill(' ');
		out << " | " << std::setprecision(2) << std::fixed << theSong.m_price << " |";
		return out;
	}
}