#include "DataBase.h"
#include <algorithm>
using namespace std;

DataBase::DataBase(){
	this->currentPos = 0;
}


void DataBase::addM(const Movie& m){
	vector<Movie>::iterator v = this->list.begin();
	while (v != this->list.end()) {
		if (v->getTitle() == m.getTitle())
			throw 1;
		v++;
	}
	this->list.push_back(m);
	
}

void DataBase::deleteM(const Movie& m) {
	
	std::vector<Movie>::iterator v = this->list.begin();
	while (v != this->list.end()) {
		if (v->getTitle() == m.getTitle())
			this->list.erase(v);
		v++;
	}
}

Movie DataBase::currentMovie(){
	if (this->currentPos == list.size())
		this->currentPos = 0;
	return this->list[currentPos];
	
}

void DataBase::start() {
	if (this->list.size() == 0)
		return;
	this->list[0].play();
}

void DataBase::next() {
	this->currentPos += 1;
	if (this->currentPos == list.size())
		this->currentPos = 0;
	this->list[currentPos].play();
}

void DataBase::step() {
	this->currentPos += 1;
}
string DataBase::getMovieInfo() {
	string s;
	s = list[currentPos].printM();
	return s;
}