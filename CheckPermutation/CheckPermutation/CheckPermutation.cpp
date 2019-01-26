// CheckPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

bool CheckPermutation(const char* permutationString1, const char* permutationString2);
int main()
{
	static const char* permutationString1 = "dtogg";
	static const char* permutationString2 = "godgt";
	static const char* permutationString3 = "cat";

	bool result = CheckPermutation(permutationString1, permutationString2);
	printf("Result: %d", result);

	int x = 0;
	cin >> x;
    return 0;
}

bool CheckPermutation(const char* permutationString1, const char* permutationString2)
{
	bool result = true;
	if (permutationString1 != nullptr &&
		permutationString2 != nullptr &&
		strlen(permutationString1) == strlen(permutationString2))
	{
		char letters[26];
		memset(letters, 0, sizeof(letters));

		for (int i = 0; i < strlen(permutationString1); i++)
		{
			letters[permutationString1[i] - 'a']++;
		}
		
		for (int i = 0; i < strlen(permutationString1); i++)
		{
			if(letters[permutationString2[i] - 'a'] == 0)
			{
				result = false;
				break;
			}

			else
			{
				letters[permutationString2[i] - 'a']--;
			}
		}

	}
	else
	{
		result = false;
	}
	return result;
}