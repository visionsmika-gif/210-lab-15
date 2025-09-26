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
	void print() const {
		cout << "Movie: " << getTitle() << "\n";
		cout << "\tYear released: " << getReleaseYear() << "\n";
		cout << "\tScreenwriter: " << getScreenWriter() << "\n";
	}
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

	// Ensure that file is open
	ifstream movieFile;
	movieFile.open("input.txt");
	if (!movieFile) {
		cout << "Unable to open file.";
		return 1;
	}

	// Read file into temporary movement object
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