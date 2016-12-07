#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileToArr(string fileName, bool **arr2D);

void frequent1Set(bool **arr2D, long transNum, long items, int minSupport, string outFile);

string getFileName(double &items, double &transNum);

#endif