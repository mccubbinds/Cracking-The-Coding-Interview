// LastKLines.cpp : Defines the entry point for the console application.
//
// Question: Write a method to print the last K lines of an input file using C++.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void PrintLastKLinesFromFile(ifstream& myfile, const uint32_t numberOfLines);

#define INPUT_FILE "KLinesExample.txt"//"E:\Career\Interview materials\Practice Problems\LastKLines\KLinesExample.txt"
#define NUMBER_OF_LAST_K_LINES 3

int main()
{
	ifstream myfile;
	PrintLastKLinesFromFile(myfile, NUMBER_OF_LAST_K_LINES);
    return 0;
}

void PrintLastKLinesFromFile(ifstream& myfile, uint32_t numberOfLinesToPrint)
{
	int numberOfLinesInFile = 0;
	string line;

	/*Solution 1 requires two reads of the file which is costly*/

	/*myfile.open("KLinesExample.txt");
	if (myfile.is_open()) 
	{
		while (myfile.peek() != EOF)
		{
			if(getline(myfile, line))
			{
				numberOfLinesInFile++;
			}
		}
		myfile.close();
	}

	myfile.open("KLinesExample.txt"); if (myfile.is_open())
	{
		for (int i = 0; i < numberOfLinesInFile; i++)
		{
			if (getline(myfile, line))
			{
				if (i >= numberOfLinesInFile - numberOfLinesToPrint)
				{
					cout << line + "\r\n";
				}
			}
		}
		myfile.close();
	}*/

	/*Solution 2 uses a circular buffer of the length of the number lines to print. This limits the number of file reads to 1. O(N) where N is the number of lines in the file.*/
	string linesToPrint[NUMBER_OF_LAST_K_LINES];

	myfile.open("KLinesExample.txt");
	if (myfile.is_open())
	{
		while (myfile.peek() != EOF)
		{
			getline(myfile, linesToPrint[numberOfLinesInFile % numberOfLinesToPrint]);
			numberOfLinesInFile++;
		}
		myfile.close();
	}

	for (int indexOfBuffer = 0; indexOfBuffer < numberOfLinesToPrint; indexOfBuffer++)
	{
		int startingIndex = 0 + indexOfBuffer;
		
		if (numberOfLinesInFile > numberOfLinesToPrint)
		{
			startingIndex = (indexOfBuffer + numberOfLinesInFile) % numberOfLinesToPrint;
		}

		if(!linesToPrint[startingIndex].empty())
		cout << linesToPrint[startingIndex] + "\r\n";
	}

	int x;
	cin >> x;
}

