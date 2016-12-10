#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "functions.h"
#include "timerSystem.h"


using namespace std;


int main()
{
	string outFile = "report.txt";
	TimerSystem timer;

	/*
	string fileName;
	string line;
	// Need to add support to read this info from file name
	double items;
	double transNum;

	fileName = getFileName(items, transNum);
	
	items = items * 1000;
	transNum = transNum * 1000;
	*/
	
	// For work on test file
	string fileName = "T5.N0.01K.D0.02K.txt";
	long transNum = 20, items = 10, avgLen = 5;
	int minSupport = 2;
	
	// creates 2D array of total number of items x total number of transactions
	bool **arr2D = new bool *[transNum]();
	for (long i = 0; i < transNum; i++)
	{
		arr2D[i] = new bool[items]();
	}
	
	fileToArr(fileName, arr2D);
	
	
	for (long i = 0; i < transNum; i++)
	{
	for (long j = 0; j < items; j++)
	{
	cout << arr2D[i][j] << " ";
	}
	cout << endl;
	}

	frequent1Set(arr2D, transNum, items, minSupport, outFile);

	pause();
}


