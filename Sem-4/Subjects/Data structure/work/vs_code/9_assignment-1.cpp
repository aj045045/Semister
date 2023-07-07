/*
	9) Write a program to create compact matrix from spares matrix using 2-D array and make a transpose of matrix.
*/

#include <iostream>
using namespace std;

int choice()
{
	int ch;
	cout << "\n\n1. Using 1-d array" << endl;
	cout << "2. Using 2-d array" << endl;
	cout << "3. Transpose the array" << endl;
	cout << "4. EXIT" << endl;
	cin >> ch; 
	return ch;
}
int main()
{
	int sparseMatrix[4][5] =
	{
		{0,0,0,4,0},
		{6,5,0,0,0},
		{0,0,6,0,0},
		{0,0,4,4,0}
	};
	do {
		switch (choice())
		{
		case 1: {
			int row[4]={}, col[5]={}, value[20]={}, k = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
					if (sparseMatrix[i][j] != 0)
					{
						row[k] = i;
						col[k] = j;
						value[k] = sparseMatrix[i][j];
						k++;
					}

			cout << "Convert 2-D array to 1-D" << endl;
			k = 0;
			cout << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (row[k] == i && col[k] == j)
					{
						cout << value[k];
						k++;
					}
					else
						cout << "0";
				}
				cout << endl;
			}
			break;
		}
		case 2: {
			int compactMatrix[3][10], size = 0, k = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
					if (sparseMatrix[i][j] != 0)
					{
						compactMatrix[0][k] = i;
						compactMatrix[1][k] = j;
						compactMatrix[2][k] = sparseMatrix[i][j];
						k++; size++;
					}
			k = 0;
			cout << "Printing the values" << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (compactMatrix[0][k] == i && compactMatrix[1][k] == j)
					{
						cout << compactMatrix[2][k];
						k++;
					}
					else
						cout << "0";
				}cout << endl;
			}
			break;
		}
		case 3: {
			int compactMatrix[3][10], size = 0, k = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
					if (sparseMatrix[i][j] != 0)
					{
						compactMatrix[0][k] = j;
						compactMatrix[1][k] = i;
						compactMatrix[2][k] = sparseMatrix[i][j];
						k++; size++;
					}
			k = 0;
			cout << "Printing the values" << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (compactMatrix[0][k] == j && compactMatrix[1][k] == i)
					{
						cout << compactMatrix[2][k];
						k++;
					}
					else
						cout << "0";
				}cout << endl;
			}
			break;
		}
		case 4: {
			exit(0);
			break;

		}
		default: {
			cout << "INVALID OPTION !" << endl;
			break;
		}
		}
	} while (true);
	return 0;
}
