#include "Movie.h"
#include <Windows.h>

Movie::Movie() : title{ "" }, gen{ "" }, link{ "" }, year{ 0 }, likes{ 0 }
{
}

Movie::~Movie()
{
}

Movie::Movie(std::string title, std::string gen, std::string link, int year, int likes){
	this->title = title;
	this->gen = gen;
	this->link = link;
	this->year = year;
	this->likes = likes;
}

void Movie::play(){
	ShellExecuteA(NULL, NULL, "chrome.exe", this->link.c_str(), NULL, SW_MAXIMIZE);
}

void Movie::increaseLikes() {
	this->likes=this->likes+1;
}

std::string Movie::getTitle() const {
	return title;
}

std::string Movie::getGenre() const {
	return gen;
}

std::string Movie::getLink() const {
	return link;
}

std::string Movie::printM() {
	std::string movie= "Title: " + title + " Gen: " + gen +" Year: " +std::to_string(year)+" Likes: " + std::to_string(likes);
	return movie;
}
std::string Movie::movieFileName() {
	std::string movie = title + " , " + gen + " , "+ link +" , " + std::to_string(year) + " , " + std::to_string(likes);
	return movie;
}

int Movie::getLikes() const {
	return likes;
}

int Movie::getYear() const {
	return year;
}