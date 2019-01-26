// OneAway.cpp : Checks two strings to see if they are one edit away. Insert char, delete char or edit char.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include <stdlib.h>

using namespace std;

bool IsOneAway(char* string1, char* string2)
{
	bool isOneAway = false;

	char* s1p1;
	char* s1p2;
	char* s2p1;
	char* s2p2;

	if (abs((int)strlen(string1) - (int)strlen(string2)) <= 1)
	{
		s1p1 = string1;
		s1p2 = &string1[strlen(string1) - 1];
		s2p1 = string2;
		s2p2 = &string2[strlen(string2) - 1];

		bool p1EditFound = false, p2EditFound = false;

		do
		{
			if (!p1EditFound)
			{
				if (*s1p1 == *s2p1)
				{
					s1p1++;
					s2p1++;
				}
				else
				{
					p1EditFound = true;
				}
			}
			
			if (!p2EditFound)
			{
				if (*s1p2 == *s2p2)
				{
					s1p2--;
					s2p2--;
				}
				else
				{
					p2EditFound = true;
				}
			}

		} while ((s1p1 <= s1p2) && (s2p1 <= s2p2) && ((p1EditFound != true) || (p2EditFound != true)) && !((s1p1 == s1p2) && (s2p1 == s2p2)));

		if ((p1EditFound == false) || (p2EditFound == false))
		{
			isOneAway = true;
		}
	}
	return isOneAway;
}

int main()
{
	char* string1 = "pale";
	char* string2 = "bake";

	printf("IsOneAway? %d", IsOneAway(string1, string2));

	int i = 0;
	cin >> i;
    return 0;
}

