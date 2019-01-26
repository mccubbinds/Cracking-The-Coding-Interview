// URLify.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>

//#pragma warning(disable : 4996)

using namespace std;

void URLify(char* InputString, int sizeOfString);
string URLify(string InputString);
char* URLify(char* InputString);

int main()
{
	char* InputString = "Mr John Smith";

	const char* test = URLify(InputString);

	printf("%s", test);
	return 0;
}

void URLify(char* InputString, int sizeOfInputString)
{
	int lengthOfString;
	const char* replacementString = "%20";
	char* destinationPointer;

	char* pointerToComma = strchr(InputString, ',');
	lengthOfString = strtol(++pointerToComma, &destinationPointer, 0);
	memset(&InputString[lengthOfString], '\0', sizeOfInputString - lengthOfString);

	int numberOfWhiteSpaces = 0;
	for (int i = 0; i < lengthOfString; i++)
	{
		if (InputString[i] == ' ')
		{
			numberOfWhiteSpaces++;
		}
	}

	int index = lengthOfString + (numberOfWhiteSpaces * 2) - 1;

	for (int i = lengthOfString - 1; i >= 0; i--)
	{
		if (InputString[i] == ' ')
		{
			index -= 2;
			memcpy(&InputString[index], replacementString, strlen(replacementString));
		}
		else
		{
			memcpy(&InputString[index], &InputString[i], 1);
		}

		index--;
	}
}

string URLify(string InputString)
{
	string returnString;
	int returnStringIndex = 0, inputStringIndex = 0;

	for (inputStringIndex; inputStringIndex < InputString.length(); inputStringIndex++)
	{
		if (InputString[inputStringIndex] == ' ')
		{
			returnString += "%20";
			returnStringIndex += 3;
		}
		else
		{
			returnString += InputString[inputStringIndex];
			returnStringIndex++;
		}
	}

	return returnString;
}

char* URLify(char* InputString)
{
	char* test = "This is a test.";

	return test;
}