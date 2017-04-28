#pragma once
#include "DynamicVector.h"
#include "Movie.h"
#include <vector>

class DataBase
{
protected:
	std::vector<Movie> list;
	int currentPos;
public:
	DataBase();
	void addM(const Movie& m);
	void deleteM(const Movie& m);
	Movie DataBase::currentMovie();
	void start();
	void next();
	void step();
	int isData() const { return list.size() == 0;}
	int getS() const { return list.size(); }
	std::string getMovieInfo();
};
