#include "HTMLFILE.h"

using namespace std;

void HTMLFILE::write() {
	ofstream f(this->filename);
	if (!f.is_open())
		cout << "Not open";
	f << "<!DOCTYPE html>\n";
	f << "<html>" << "\n";
	f << "<head>" << "\n";
	f << "<title>Watchlist</title>" << "\n";
	f << "</head>" << "\n";
	f << "<body>" << "\n";
	f << "<table border = 1>" << "\n";
	f << "<tr>" << "\n";
	f << "<td>Title</td>" << "\n";
	f << "<td>Genre</td>" << "\n";
	f << "<td>Year</td>" << "\n";
	f << "<td>Likes</td>" << "\n";
	f << "<td>Youtube link</td>" << "\n";
	f << "</tr>" << "\n";
	for (auto i : this->list)
	{
		f << "<tr>";
		f << "<td>" << i.getTitle() << "</td>" << "\n";
		f << "<td>" << i.getGenre() << "</td>" << "\n";
		f << "<td>" << i.getYear() << "</td>" << "\n";
		f << "<td>" << i.getLikes() << "</td>" << "\n";
		f << "<td><a href =" << i.getLink() << "> Trailer</a></td>" << "\n";
		f << "</tr>";
	}
	f << "</table>" << "\n";
	f << "</body>" << "\n";
	f << "</html>" << "\n";
	f.close();
}

void HTMLFILE::show() {
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	ShellExecuteA(NULL, NULL, "chrome.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}