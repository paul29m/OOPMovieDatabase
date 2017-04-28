#pragma once
#include "DataBase.h"
#include "Movie.h"
#include "DynamicVector.h"
#include <vector>
class Repository {
private:
	std::vector<Movie> movies;
	std::string filename;

public:
	Repository(const std::string& filename); //onstructor
	
	/*
	Adds a movie to the repo
	Input: m- movie instance
	Output: nothing - if the movie was added
           throw a message - otherwise 
	*/
	void addMovie(const Movie& m);
	
	/*
	Updates a movie to the repo
	Input: m- movie instance
	Output: nothing - if the movie was updated
          throw a message - otherwise 
	*/
	void updateMovie(const Movie& m);
	
	/*
	Adds a movie to the repo
	Input:m- movie instance
	Output: nothing - if the movie was removed
		  throw a message - otherwise 
	*/
	void deleteMovie(const Movie& m);
	
	/*
	Increase movie likes
	Input:m - movie instance
	Output:-
	*/
	void likes( Movie& m);

	/*
	Show movies of a specific genre
	Input: gen - st::strig type. the genre 
	output: a DataBase of movies
	*/
	DataBase show(std::string gen);

	std::vector <Movie> getMovies() const {return movies;} //Returns the Dyn vector of movies
private:
	void readFF();//read from file
	void writeTF();//store the info in file
};

//Tests
void testRepo(); 