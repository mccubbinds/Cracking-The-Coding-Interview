// StringCompression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

string CompressString(string stringToCompress)
{
	stringstream compressedStringStream;
	int countOfCharacter = 1;

	for (int i = 0; i < stringToCompress.length(); i++)
	{
		if (((i + 1) <= stringToCompress.length()) && (stringToCompress[i] == stringToCompress[i + 1]))
		{
			countOfCharacter++;
		}

		else
		{
			compressedStringStream << stringToCompress[i] << countOfCharacter;
			countOfCharacter = 1;
		}
	}

	return compressedStringStream.str();
}

int main()
{
	string stringToCompress = "AAABBBCyyyyyyyyyCCddd";

	cout << CompressString(stringToCompress);

	int x;
	cin >> x;

	return 0;
}

