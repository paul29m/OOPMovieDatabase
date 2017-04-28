#include "Controller.h"
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>


void Controller::addMovieToWatchList(Movie& m){
	return this->movieList.addM(m);
}


void Controller::deleteMovieFromWatchList(Movie& m) {
	this->movieList.deleteM(m);
}

void Controller::increaseLikesRepo(Movie& m) {
	this->repo.likes(m);
}

DataBase Controller::showGenre(std::string gen) {
	this->listM=this->repo.show(gen);
	return this->listM;
}

void Controller::addMovieToRepository(Movie &m) {
	this->repo.addMovie(m);
}

void Controller::updateMovieRepository(Movie &m) {
	 this->repo.updateMovie(m);
}

void Controller::removeMovieRepository(Movie &m) {
	 this->repo.deleteMovie(m);
}



void testCtrl() {
	Repository repo("t.txt");
	Controller ctrl(repo);
	Movie m1{ "Columbiana", "Drama", "https://www.youtube.com/watch?v=2fngvQS_PmQ", 2005 , 324 };
	Movie m2{ "Inception", "Drama", "https://www.youtube.com/watch?v=2fngvQS_PmQ", 2015 , 5363324 };
	ctrl.addMovieToRepository(m1);
	std::vector <Movie> l = ctrl.getMoviesRepo();
	assert(l.size() == 1);
	ctrl.addMovieToRepository(m2);
	l = ctrl.getMoviesRepo();
	assert(l.size() == 2);
	ctrl.removeMovieRepository(m1);
	ctrl.removeMovieRepository(m2);
}