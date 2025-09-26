// COMSC-210 | Lab 15 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Movie {
public:
	// Set functions
	void setScreenWriter(const string& writer)	{ screenWriter = writer; }
	void setReleaseYear(int year)				{ releaseYear = year; }
	void setTitle(string t)						{ title = t; }

	// Get functions
	string getScreenWriter() const	{ return screenWriter; }
	int getReleaseYear() const		{ return releaseYear; }
	string getTitle() const			{ return title; }

	// Function to print movie information
	void print() const;
private:
	string screenWriter;
	int releaseYear;
	string title;
};

int main() {
	Movie tempMovie;
	string title;
	int year;
	string writer;
	vector<Movie> movies;

	// Ensure the file is open
	ifstream movieFile;
	movieFile.open("input.txt");
	if (!movieFile) {
		cout << "Unable to open file.";
		return 1;
	}

	// Read the file into temporary Movie object
	while (getline(movieFile, title)) {
		movieFile >> year;
		movieFile.ignore();
		getline(movieFile, writer);

		tempMovie.setTitle(title);
		tempMovie.setReleaseYear(year);
		tempMovie.setScreenWriter(writer);

		// Store the movies in a vector
		movies.push_back(tempMovie);
	}

	movieFile.close();

	// Output the movies
	for (Movie m : movies) {
		m.print();
		cout << "\n";
	}

	return 0;
}

// Implementation for print member function
void Movie::print() const {
	cout << "Movie: " << getTitle() << "\n";
	cout << "\tYear released: " << getReleaseYear() << "\n";
	cout << "\tScreenwriter: " << getScreenWriter() << "\n";
}