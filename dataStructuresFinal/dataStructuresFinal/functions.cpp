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


string getFileName(double &items, double &transNum)
{
	string transLength, numItems, numTrans, fileName;
	string::size_type sz;

	cout << "The following data will determine which file to open..." << endl << endl;

	cout << "Please enter the average Transaction length: ";
	cin >> transLength;
	cout << "Please enter the number of distinct items in terms of how many thousand (ex. 20 = 0.02 and 10000 = 10): ";
	cin >> numItems;
	cout << "Please enter the number of transactions in terms of how many thousand: ";
	cin >> numTrans;
	
	fileName = "T" + transLength + ".N" + numItems + "K.D" + numTrans + "K.txt";
	items = stod(numItems, &sz);
	transNum = stod(numTrans, &sz);




	return fileName;
}