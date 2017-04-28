#include "UI.h"
#include "Movie_Validator.h"
#include "DataBaseFile.h"
#include "CSVFILE.h"
#include "HTMLFILE.h"
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

void UI::menu(){
	cout << endl;
	cout << "1 - Admin mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit" << endl;

}

void UI::userMenu() {
	cout << endl;
	cout << "1 - Show all the movies having a specific genre" << endl;
	cout << "2 - Display your watch list" << endl;
	cout << "0 - retrun" << endl;
}

void UI::adminMenu() {
	cout << endl;
	cout << "1 - add movie" << endl;
	cout << "2 - update movie" << endl;
	cout << "3 - remove movie" << endl;
	cout << "4 - show all movies" << endl;
	cout << "0 - return" << endl;
}
void UI::watchListMenu() {
	cout << endl;
	cout << "1 - see the next movie" << endl;
	cout << "2 - delete movie from watch list and rate it" << endl;
	cout << "3 - save and show in a text or html file" << endl;
	cout << "0 - return" << endl;
}

void UI::genreMenu() {
	cout << endl;
	cout << "1 - see the next movie" << endl;
	cout << "2 - add the movie to watch list" << endl;
	cout << "0 - return" << endl;
}

void UI::addMovieToCtrl() {
	int likes, year;
	cout << endl << "Enter movie title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter genre: " << endl;
	std::string gen;
	getline(cin, gen);
	cout << "Enter year: " << endl;
	cin >> year;
	cout << "Enter likes: " << endl;
	cin >> likes;
	cin.ignore();
	cout << "Enter the link that contains the movie trailer: " << endl;
	std::string link;
	getline(cin, link);
	Movie m{ title,gen,link,year,likes };
	try
	{
		MovieValidator v;
		v.validate(m);
		delete[] &v;
	}
	catch (ValidationException& ex)

	{
		std::cout << ex.getMessage() << std::endl;
		return;
	}
	try
	{
		this->ctrl.addMovieToRepository(m);
	}
	catch (char *msg)
	{
		cout << msg << endl;
		return;
	}
	cout << "Movie was succesfully added.\n";
}

void UI::updateMovieCtrl() {
	int likes, year;
	cout << endl << "Enter movie title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter genre: " << endl;
	std::string gen;
	getline(cin, gen);
	cin.ignore();
	cout << "Enter year: " << endl;
	cin >> year;
	cout << "Enter likes: " << endl;
	cin >> likes;
	cin.ignore();
	cout << "Enter the link that contains the movie trailer: " << endl;
	std::string link;
	getline(cin, link);
	Movie m{ title,gen,link,year,likes };

	try
	{
		MovieValidator v;
		v.validate(m);
		delete[] &v;
	}
	catch (ValidationException& ex)

	{
		std::cout << ex.getMessage() << std::endl;
		return;
	}
	try
	{
		this->ctrl.updateMovieRepository(m);
	}
		catch (char *msg)
		{
			cout << msg << endl;
			return;
		}
		cout << "Movie was succesfully updated.\n";
}

void UI::removeMovieFromCtrl() {
	cout << endl << "Enter movie title: " << endl;
	std::string title;
	getline(cin, title);
	cin.ignore();
	Movie m{ title,"","",0,0};
	try
	{
		this->ctrl.removeMovieRepository(m);
	}
	catch (char *msg)
	{
		cout << msg << endl;
		return;
	}
	cout << "Movie was succesfully updated.\n";
}

void UI::displayAllMovies() {
	std::vector<Movie> l = this->ctrl.getMoviesRepo();
	for (vector<Movie>::iterator i = l.begin(); i != l.end(); i++) {
		cout<<i->printM()<<endl;
	}
}

void UI::stratUI() {
	while (true) {
		UI::menu();
		int command;
		cout << "Choose one: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1) {
			while (true) {
				UI::adminMenu();
				int commandAdmin{ 0 };
				cout << "Input the command: ";
				cin >> commandAdmin;
				cin.ignore();
				if (commandAdmin == 0)
					break;
				switch (commandAdmin) {
				case 1:
					this->addMovieToCtrl();
					break;

				case 2:
					this->updateMovieCtrl();
					break;

				case 3:
					this->removeMovieFromCtrl();
					break;
				case 4:
					this->displayAllMovies();
					break;

				}
			}
		}
		if (command == 2) {
			while (true) {
				UI::userMenu();
				int commandUser;
				cout << "Input the command: ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				if (commandUser == 1){
						cout << "Enter genre: " << endl;
						std::string gen;
						getline(cin, gen);
						DataBase list = this->ctrl.showGenre(gen);
						if (this->ctrl.showGenre(gen).isData()) {
							cout << "There are no movies in the list" << endl;
							break;
						}
						list.start();
						cout << list.getMovieInfo() << endl;
						while (true) {
							UI::genreMenu();
							int commandgen;
							cout << "Input the command: ";
							cin >> commandgen;
							cin.ignore();
							if (commandgen == 0)
								break;
							if (commandgen ==1){
									list.next();
									cout << list.getMovieInfo() << endl;
								}
							if (commandgen ==2){
									Movie m = list.currentMovie();
									int res = 0;
									this->ctrl.addMovieToWatchList(m);
									if (res == -1)
										cout << "Movie is already in the watch list." << endl;
									else
										cout << "Movie succesfully added to watch list." << endl;
									list.next();
									cout << list.getMovieInfo() << endl;
							}
						}
					}
				else
					if(commandUser==2){
						DataBase watchlist = this->ctrl.getWatchList();
						if (watchlist.isData()) {
							cout << "There are no movies in the list" << endl;
							break;
						}
						watchlist.start();
						cout << watchlist.getMovieInfo() << endl;
						int step = 0;
						while (true) {
							if (watchlist.isData()) {
								cout << "Your watch list is empty." << endl;
								break;
							}
							if (step == 2) {
								watchlist.start();
								cout<< watchlist.getMovieInfo() << endl;
							}
							UI::watchListMenu();
							int commandW;
							cout << "Input the command: ";
							cin >> commandW;
							cin.ignore();
							if (commandW == 0)
								break;
							if (commandW == 1){
								step = 0;
								watchlist.next();
								cout << watchlist.getMovieInfo() << endl;
							}
							if (commandW == 2){
								watchlist = this->ctrl.getWatchList();
								Movie m = watchlist.currentMovie();
								watchlist.deleteM(m);
								int c;
								cout << "Do you want to like this movie?\n1-yes 0-no\n";
								cin >> c;
								if (c) 
									this->ctrl.increaseLikesRepo(m);
								watchlist = this->ctrl.getWatchList();
								step = 2;
							}
							if (commandW == 3) {
								cout << "Enter file name: " << endl;
								std::string name; 
								getline(cin, name);
								int type = 0;
								while (true) {
									cout << "Input The type\n 1-CSV\n 2-HTML\n";
									cin >> type;
									if (type == 1 || type == 2)
										break;
									else
										cout << "Try again\n";
								}
								DataBaseFile* p;
								if (type == 1)
									p = new CSVFILE{};
								else
									p = new HTMLFILE{};

								for (int i = 0; i != watchlist.getS();i++)
								{
									p->addM(watchlist.currentMovie());
									watchlist.step();
								}
								p->setFileName(name);
								p->write();
								p->show();
							}
						}
					}
				}
			}
		if(command>2)
			cout << "Enter valid command!" << endl;
	}
}
