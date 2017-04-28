#pragma once
#include <string>
class Movie
{
private:
	std::string title;
	std::string gen;
	std::string link;
	int year;
	int likes;
public:
	Movie();
	~Movie();
	Movie(std::string title, std::string gen, std::string link, int year, int likes);
	std::string getTitle() const;
	std::string getGenre() const;
	std::string getLink() const;
	int getYear() const;
	int getLikes()const;
	std::string printM();
	std::string movieFileName();
	void play();
	void increaseLikes();
};