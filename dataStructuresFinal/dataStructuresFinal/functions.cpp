#include "functions.h"
#include "queue.h"
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

// Working frequent1Set
/*
// determines frequent 1-itemsets
// DONE
void frequent1Set(bool **arr2D, long transNum, long items, int minSupport, string outFile)
{
int sum = 0, item = 0;


// creates report file
fstream output;
output.open(outFile, ios_base::app);


output << "1-itemset" << endl;


// reads each item in array adding number of appearances
for (long i = 0; i < items; i++)
{
for (long j = 0; j < transNum; j++)
{
if (arr2D[j][i])
{
sum++;
}
}
if (sum >= minSupport)
{
output << i << " (" << sum << ")" << endl;
}
sum = 0;
}
}*/// 


// WIP
void frequent1Set(bool **arr2D, long transNum, long items, int minSupport, string outFile)
{
	int sum = 0, item = 0, size, n = 2;
	Queue<int> setQ;

	// creates report file
	fstream output;
	output.open(outFile, ios_base::app);

	output << "1-itemset" << endl;

	// reads each item in array adding number of appearances
	for (long i = 0; i < items; i++)
	{
		for (long j = 0; j < transNum; j++)
		{
			if (arr2D[j][i])
			{
				sum++;
			}
		}
		if (sum >= minSupport)
		{
			output << i << " (" << sum << ")" << endl;
			setQ.enqueue(i);
		}
		sum = 0;
	}

	size = setQ.getCount();
	int *oneSet = new int[size];

	// Loads all frequent 1-itemsets into array
	for (int i = 0; i < size; i++)
	{
		oneSet[i] = setQ.dequeue();
	}

}

void loadArray(int *arr, int size, int **arr2D, int &comboNum)
{
	for (int i = 0; i < size; i++)
	{
		arr2D[comboNum][i] = arr[i];
	}
	comboNum++;
}

void Apriori(bool **arr2D, int *oneSet, int size, long transNum, long items, int minSupport, string outFile)
{
	for (int k = 2; oneSet[k - 1] != NULL; k++)
	{
		double numCombos = factorial(size, k);
		double **allCombos = new double *[numCombos];
		for (int i = 0; i < size; i++)
		{
			allCombos[i] = new double[k];
		}

		for (int t = 0; t < transNum; t++)
		{

		}
		/*
		Ck = apriori_gen(Lk-1);
		*/
	}
}

double factorial(double setSize, double comboSize)
{
	double nFac = 1, rFac = 1, fac;
	
	for (double i = setSize; i > setSize - comboSize; i--)
	{
		nFac *= i;
	}

	for (double i = comboSize; i > 0; i--)
	{
		rFac *= i;
	}

	fac = nFac / rFac;
	return fac;
}



void makeCombo(int offset, int k, int pos, int arrSize, int *arr, int *oneSet, int oneSetSize)
{
	if (k == 0)
	{
		for (int i = 0; i < arrSize; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = offset; i < oneSetSize - k + 1; ++i)
	{
		arr[pos] = oneSet[i];
		makeCombo(i + 1, k - 1, pos + 1, arrSize, arr, oneSet, oneSetSize);
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

void pause()
{
	cout << endl << "Please press enter to continue...";
	cin.get();
}