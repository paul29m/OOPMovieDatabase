#include <iostream>
#include "DynamicVector.h"
#include "Movie.h"
#include "DataBase.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

using namespace std;
int main() {
	testRepo();
	testCtrl();
	Repository repo("Movies.txt");
	Controller ctrl(repo);
	UI ui(ctrl);
	ui.stratUI();
	return 0;
}
