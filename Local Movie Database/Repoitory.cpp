#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include <assert.h>
#include <iostream>
#include "DataBase.h"

using namespace std;
Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFF();
}

void Repository::addMovie(const Movie& m) {
	std::string name = m.getTitle();
	vector<Movie>::iterator v = this->movies.begin();
	while (v != this->movies.end()) {
		if (v->getTitle() == m.getTitle())
			throw "Movie already in list";
		v++;
	}
	this->movies.push_back(m);
	this->writeTF();
}
void Repository::updateMovie(const Movie&m) {
	std::string name = m.getTitle();
	vector<Movie>::iterator v = this->movies.begin();
	while (v != this->movies.end()) {
		if (v->getTitle() == m.getTitle()) {
			this->movies.erase(v);
			this->movies.push_back(m);
			this->writeTF();
			return;
		}
		v++;
	}
	throw "There is no movie in the list";
}

void Repository::deleteMovie(const Movie&m) {
	std::string name = m.getTitle();
	vector<Movie>::iterator v = this->movies.begin();
	while (v != this->movies.end()) {
		if (v->getTitle() == m.getTitle()) {
			this->movies.erase(v);
			this->writeTF();
			return;
		}
		v++;
	}
	throw "There is no movie in the list";
}

void Repository::readFF() {
	ifstream file(this->filename);
	string line;
	while (getline(file, line))
	{
		string tokens[20];
		int length = 0;
		tokenize(line, ',', tokens, length);
		if (length != 5)
			continue;

		Movie m{ tokens[0], tokens[1], tokens[2], stoi(tokens[3]), stoi(tokens[4]) };
		this->addMovie(m);

	}
	file.close();
}
void Repository::writeTF() {
	ofstream file(this->filename);
	if (this->getMovies().size() == 0)
	{
		file << " ";
		file.close();
		return;
	}
	std::string fileName="";
	std::vector <Movie> elems = this->getMovies();
	for (vector<Movie>::iterator i=this->movies.begin(); i !=this->movies.end(); i++) {
		fileName = fileName + "\n" + i->movieFileName();
	}
	file << fileName;
	file.close();
}

void Repository::likes( Movie& m) {
	std::string name = m.getTitle();
	std::vector <Movie> list = this->getMovies();
	vector<Movie>::iterator v = this->movies.begin();
	while (v != this->movies.end()) {
		if (v->getTitle() == name)
			v->increaseLikes();
		list.push_back(*v);
		v++;
	}
	this->movies = list;
	this->writeTF();
}

DataBase Repository::show(std::string gen) {
	std::vector <Movie> list = this->getMovies();
	DataBase l;
	if (gen == "") {
		vector<Movie>::iterator v = this->movies.begin();
		while (v != this->movies.end()) {
				l.addM(*v);
			v++;
		}
	}
	else {
		vector<Movie>::iterator v = this->movies.begin();
		while (v != this->movies.end()) {
			if (v->getGenre() == gen)
				l.addM(*v);
			v++;
		}
	}
	return l;
}

void testRepo() {
	Repository repo("t.txt");
	Movie m1{ "Inception", "Drama", "https://www.youtube.com/watch?v=2fngvQS_PmQ", 2005 , 324 };
	Movie m2{ "Columbiana", "Drama", "https://www.youtube.com/watch?v=2fngvQS_PmQ", 2005 , 324 };
	std::vector < Movie > list = repo.getMovies();
	assert(list.size() == 0);
	repo.addMovie(m1);
	list = repo.getMovies();
	assert(list.size() == 1);
	repo.addMovie(m2);
	list = repo.getMovies();
	assert(list.size() == 2);
	repo.deleteMovie(m1);
	repo.deleteMovie(m2);
	list = repo.getMovies();
	assert(list.size() == 0);
}