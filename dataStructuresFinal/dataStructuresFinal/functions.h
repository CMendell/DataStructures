#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileToArr(string fileName, bool **arr2D);

void frequent1Set(bool **arr2D, long transNum, long items, int minSupport, string outFile);

string getFileName(double &items, double &transNum);

void pause();

double factorial(double setSize, double comboSize);

void Apriori(bool **arr2D, int *oneSet, int size, long transNum, long items, int minSupport, string outFile);

void makeCombo(int offset, int k, int pos, int arrSize, int *arr, int *oneSet, int oneSetSize);
#endif