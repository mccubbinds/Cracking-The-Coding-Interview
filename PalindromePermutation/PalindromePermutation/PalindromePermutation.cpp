// PalindromePermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"

using namespace std;

bool PalindromePermutation(char* InputString, int sizeOfInputString, int* table, int tableSize);
void CreateTable(char* InputString, int sizeOfInputString, int* table, int tableSize);
bool CheckTableForPalindrome(int* table, int tableSize);

int main()
{
	const int SizeOfInputString = 8;
	char* InputString = "tactzz coa";
	const int SizeOfTableBuffer = 8;
	int TableBuffer[SizeOfTableBuffer];
	memset(TableBuffer, 0, SizeOfTableBuffer);

	printf("%d", PalindromePermutation(InputString, SizeOfInputString, TableBuffer, SizeOfTableBuffer));

	int d;
	cin >> d;

    return 0;
}


bool PalindromePermutation(char* InputString, int sizeOfInputString, int* table, int tableSize)
{
	CreateTable(InputString, sizeOfInputString, table, tableSize);
	return CheckTableForPalindrome(table, tableSize);
}


void CreateTable(char* InputString, int sizeOfInputString, int* table, int tableSize)
{
	for (int i = 0; i < sizeOfInputString; i++)
	{
		if (InputString[i] >= 'a' &&
			InputString[i] <= 'z')
		{
			table[(InputString[i] - 'a') % tableSize]++;
		}
	}
}

bool CheckTableForPalindrome(int* table, int tableSize)
{
	bool isPalindrome = true;
	int numberOfOddRepeatCharacters = 0;

	for (int i = 0; i < tableSize; i++)
	{
		if (table[i] % 2 == 1)
		{
			numberOfOddRepeatCharacters++;
			if (numberOfOddRepeatCharacters > 1)
			{
				isPalindrome = false;
				break;
			}
		}
	}

	return isPalindrome;
}

