<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "functions.h"
=======
#include "Header.h"
>>>>>>> refs/remotes/origin/master

using namespace std;

int main()
{
<<<<<<< HEAD
	string fileName;
	string line;
	// Need to add support to read this info from file name
	double items;
	double transNum;
	ifstream input;
	bool good = true, pass = true;
	stringstream stream;
	int num;


	fileName = getFileName(items, transNum);

	items = items * 1000;
	transNum = transNum * 1000;

	input.open(fileName);

	
	getline(input, line);
	stream.str(line);

	//not sure what this is for. seems to just display contents of file. should probably get rid of
	/*
	while (good)
	{
		stream >> num;
		cout << num << " ";

		if (stream.eof() && pass)
		{
			getline(input, line);
			stream.str(line);
			stream.clear();
			pass = !pass;
			cout << "Starting line 2" << endl;
		}

		if (stream.eof() && !pass)
		{
			good = !good;
			cout << "Breaking." << endl;
		}
	}*/

	// creates 2D array of total number of items x total number of transactions
	bool **arr2D = new bool *[transNum]();
	for (int i = 0; i < transNum; i++)
	{
		arr2D[i] = new bool[items]();
	}

	fileToArr(fileName, arr2D);
	
	for (int i = 0; i < transNum; i++)
	{
		for (int j = 0; j < items; j++)
		{
			cout << arr2D[i][j] << " ";
		}
		cout << endl;
	}
	
	cin.get();

	system("pause");

}
=======
	system("pause");
}
>>>>>>> refs/remotes/origin/master
