// Code a Movie class that has the screen writer, the year released, and the title as its private member variables. It has the standard setters and getters for each private member variable. Also code a print() method which prints the object data in a simple format.
// Your code should read data from an input file, using the data below, which lists data in this order: title, year released, screen writer name.
// Read this data into a temporary Movie object.Then append that object to your container.
// For your container, you can choose an <array> class array or a <vector> class vector.Store your four records in this container.
// Towards the end of your main() function, output the contents of the array / vector.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Movie {
public:
	void setScreenWriter(const string& writer)	{ screenWriter = writer; }
	void setReleaseYear(int year)				{ releaseYear = year; }
	void setTitle(string t)						{ title = t; }

	string getScreenWriter() const	{ return screenWriter; }
	int getReleaseYear() const		{ return releaseYear; }
	string getTitle() const			{ return title; }

	// TODO: add print method
private:
	string screenWriter;
	int releaseYear;
	string title;
};

int main() {
	Movie movie;
	string title;
	int year;
	string writer;
	vector<Movie> movies;

	ifstream movieFile;
	movieFile.open("input.txt");
	if (!movieFile) {
		cout << "Unable to open file.";
		return 1;
	}

	while (getline(movieFile, title)) {
		

	}

	movieFile.close();

	return 0;
}