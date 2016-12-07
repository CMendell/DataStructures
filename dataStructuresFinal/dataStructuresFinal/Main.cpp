#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
	string fileName = "T5.N0.01K.D0.02K.txt";

	// Need to add support to read this info from file name
	int items = 10;
	int transNum = 20;
	
	// creates 2D array of total number of items x total number of transactions
	bool **arr2D = new bool *[items]();
	for (int i = 0; i < items; i++)
	{
		arr2D[i] = new bool[transNum]();
	}

	fileToArr(fileName, arr2D);
	
	for (int i = 0; i < items; i++)
	{
		for (int j = 0; j < transNum; j++)
		{
			cout << arr2D[i][j] << " ";
		}
		cout << endl;
	}
	
	cin.get();

}