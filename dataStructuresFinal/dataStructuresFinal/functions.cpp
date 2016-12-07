#include "functions.h"
#include <sstream>

using namespace std;

void fileToArr(string fileName, bool **arr2D)
{
	fstream input;
	input.open(fileName);
	string line;
	bool good = true;
	int num, trans = 0;

	if (!input.good())
	{
		cout << "Invalid file name." << endl;
		return;
	}

	while (!input.eof())
	{
		cout << "Starting line " << trans << endl;
		getline(input, line);
		stringstream stream(line);

		cout << line << endl;

		while (good)
		{
			stream >> num;
			if (!stream)
			{
				good = !good;
				break;
			}
			arr2D[trans][num] = true;
		}
		stream.clear();

		cout << "Line " << trans << " done." << endl;
		trans++;
	}
}