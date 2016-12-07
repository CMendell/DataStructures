#include "functions.h"
#include <sstream>

using namespace std;

void fileToArr(string fileName, bool **arr2D)
{
	fstream input;
	input.open(fileName);
	string line;
	int num, trans = 0;
	stringstream stream;

	if (!input.good())
	{
		cout << "Invalid file name." << endl;
		return;
	}

	// Checks for empty file
	if (input.eof())
	{
		return;
	}

	// Gets first line of file for parsing
	getline(input, line);
	stream.str(line);
	// Parses each line of file and sets all found numbers to true for each transaction
	while (1)
	{
		stream >> num;
		arr2D[trans][num] = true;

		if (stream.eof())
		{
			// Reads in next line if not eof
			getline(input, line);
			stream.str(line);
			stream.clear();
			trans++;

			// Checks for end of file
			if (input.eof())
			{
				return;
			}
		}
	}
	
}