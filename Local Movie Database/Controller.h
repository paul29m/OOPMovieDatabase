#pragma once
#include "Repository.h"
#include <string>
#include "DataBase.h"
#include "DataBaseFile.h"

class Controller
{
private:
	Repository repo;
	DataBase movieList; // the watch list
	DataBase listM; // the list of genre

public:
	Controller(const Repository& r) : repo(r) {}
	Repository getRepo() { return repo; }
	
	/*
	Add movie to watch list
	Input: m- movie instance
	Output: 1 - if the movie was added
		   -1 - otherwise
	*/
	void addMovieToWatchList(Movie& m);

	/*
	Delete movie from watch list
	Input: m- movie instace
	Output: -
	*/
	void deleteMovieFromWatchList(Movie& m);

	/*
	Increase movies likes
	Inpurt: m- movie instace
	Output: -
	*/
	void increaseLikesRepo(Movie& m);

	/*
	All movies of a specific genre 
	Input: gen - the genre
	Output: the list of movie having the spcific genre
	*/
	DataBase showGenre(std::string gen);

	std::vector<Movie> getMoviesRepo() const { return this->repo.getMovies(); }
	/*
	Update a movie from watch list
	Input: m- movie instance
	Output: 1 - if the movie was added
		   -1 - otherwise
	*/
	void Controller::updateMovieRepository(Movie &m);

	/*
	Remove movie from watch list
	Input: m- movie instance
	Output: 1 - if the movie was added
	-1 - otherwise
	*/
	void Controller::removeMovieRepository(Movie &m);

	/*
	Add movie to watch list
	Input: m- movie instance
	Output: 1 - if the movie was added
	-1 - otherwise
	*/
	void Controller::addMovieToRepository(Movie &m);
	
	DataBase getWatchList() const { return this->movieList; } //Return the Watch list
	DataBase getList() const { return this->listM; }//Return the list of movies
};


//tests
void testCtrl();