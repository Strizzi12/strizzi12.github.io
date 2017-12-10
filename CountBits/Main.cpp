// CountBytes.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "MyConstants.h"
#include "MyCalculator.h"
#include "MyController.h"
#include <string>

using namespace std;

const char *path = "C:\\Users\\Andi\\Downloads"; 
const char *path2 = "C:\\Users\\Andi\\Downloads\\Neuer Ordner";


int main(int argc, char* argv[])
{
	//Input Parsing
	/*if (argc < 2)
	{
	MyController::PrintHelp();
	return 0;
	}
	else
	{
	MyController::ParseInputArguments(argc, argv);
	}*/

	//Initialization
	MyController myController;
	MyCalculator myCalculator;
	myController.SetStartTime();

	//Testing area
	myController.MoreInfo = false;
	myController.DepthOfRecursion = 0;
	//myController.FilePaths.push_back(path);
	myController.FilePaths.push_back(path2);
	myController.PrintProcessTime = true;

	//Calculation area
	MyResult result;
	for (auto path : myController.FilePaths)
	{
		MyResult tempResult = myCalculator.CountBitsOf1ForPath(path.c_str(), myController);
		result.SumBit0 += tempResult.SumBit0;
		result.SumBit1 += tempResult.SumBit1;
		result.FileSize += tempResult.FileSize;
	}	

	cout << "0er: " << result.SumBit0 << endl;
	cout << "1er: " << result.SumBit1 << endl;
	cout << "Sum: " << result.FileSize * 8 << " in bits" << endl;

	myController.SetStopTime();
	myController.PrintTime();
	myController.Wait();
	return 0;
}