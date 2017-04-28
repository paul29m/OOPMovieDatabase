#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl(c) {}
	void stratUI();

private:
	static void menu();
	static void adminMenu();
	static void userMenu();
	static void watchListMenu();
	static void genreMenu();
	//static void addToWatchList();

	void addMovieToCtrl();
	void updateMovieCtrl();
	void removeMovieFromCtrl();
	void displayAllMovies();
};