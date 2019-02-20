// RotateMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void RotateMatrix(char MatrixToRotate[][5], int n)
{
	int layer, first, last, offset;
	char temp;

	for (layer = 0; layer < n/2; layer++)
	{
		first = layer;
		last = n - 1 - layer;
		for (offset = layer; offset < last; offset++)
		{
			temp = MatrixToRotate[first][first + offset]; //Top to Temp
			MatrixToRotate[first][first + offset] = MatrixToRotate[last - offset][first]; //Left to Top
			MatrixToRotate[last - offset][first] = MatrixToRotate[last][last - offset]; //Bottom to Left
			MatrixToRotate[last][last - offset] = MatrixToRotate[first + offset][last]; //Right to Bottom
			MatrixToRotate[first + offset][last] = temp; //Temp to Right
		}
	}
}

void PrintMatrix(char MatrixToRotate[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "[" << MatrixToRotate[i][j] << "] ";
		}
		cout << "\r\n";
	}

	cout << "\r\n";
}

int main()
{
	char matrix[5][5] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' };
	PrintMatrix(matrix, 5);
	RotateMatrix(matrix, 5);
	PrintMatrix(matrix, 5);

	int test;
	cin >> test;
    return 0;
}

