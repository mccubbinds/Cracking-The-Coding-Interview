// ReverseString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void Reverse(char* str);

int main()
{
	char stringToReverse[] = "Derek McCubbin\0";
	Reverse(stringToReverse);

	printf("Reversed string: %s\r\n", stringToReverse);

	int test;
	scanf_s("%d", &test);
    return 0;
}

void Reverse(char* str)
{
	char* p1;
	char* p2;

	p1 = str;
	p2 = str + (strlen(str) -1);

	while (p1 < p2)
	{
		char temp = *p1;
		*p1 = *p2; // memcpy(p1, p2, 1);
		*p2 = temp;

		p1++;
		p2--;
	}
}