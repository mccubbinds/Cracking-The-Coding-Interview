// IsUnique.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

bool IsUnique(const char* string);

int main()
{
	static const char* uniqueString = "qwertyuiop";
	static const char* repeatedCharString = "qwertyyuiop";

	bool response = IsUnique(repeatedCharString);

	printf("Is the string unique?: %d.\n", response);

	int x = 0;
	scanf_s("%d", x);
    return 0;
}

bool IsUnique(const char* string)
{
	static const int sizeOfFrequencyOfCharacters = 'z' - 'a' + 1;
	char frequencyOfCharacters[sizeOfFrequencyOfCharacters];
	memset(frequencyOfCharacters, 0, sizeof(frequencyOfCharacters));
	int i;

	for (i = 0; i < strlen(string); i++)
	{
		frequencyOfCharacters[string[i] - 'a']++;
	}

	for (i = 0; i < strlen(string); i++)
	{
		if (frequencyOfCharacters[string[i] - 'a'] > 1)
		{
			return false;
		}
	}
	
	return true;
}