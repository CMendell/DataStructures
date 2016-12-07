#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "functions.h"

using namespace std;

int main()
{
	string fileName = "T5.N0.01K.D0.02K.txt";

	// Need to add support to read this info from file name
	int items = 10;
	int transNum = 20;

	string file = "testFile.txt", line;
	ifstream input;
	input.open(file);
	bool good = true, pass = true;
	stringstream stream;
	int num;

	/*
	getline(input, line);
	stream.str(line);

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

}