#include <stdio.h>

#define SIZE 5

// adds two matrices together
void addMatrices (int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
	int m3[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printMatrix(m3);

}
// multiplies two matrices together
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
	int m3[SIZE][SIZE] = {0};
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			for(int k = 0; k < SIZE; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printMatrix(m3);
}

//transposes a matrix
void transposeMatrix(int m1[SIZE][SIZE])
{
	int m3[SIZE][SIZE] = {0};
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			m3[i][j] = m1[j][i];
		}
	}
	printMatrix(m3);
}

//prints a matrix in a readable form
void printMatrix(int m1[SIZE][SIZE])
{
	for(int i = -1; i < SIZE; i++)
	{
		for(int j = -1; j < SIZE; j++)
		{
			if(i == -1 && j == -1)
			{
				printf("\t");
			}
			else if(i == -1)
			{
				printf("Row %d \t", j);
			}
			else if(j == -1)
			{
				printf("Col %d \t", i);
			}
			else
			{
				printf("%d \t", m1[i][j]);
			}
		}
		printf("\n");
	}
}


int main()
{
	int m1 [SIZE][SIZE] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
				};

	int m2 [SIZE][SIZE] = {
		{25,24,23,22,21},
		{20,19,18,17,16},
		{15,14,13,12,11},
		{10,9,8,7,6},
		{5,4,3,2,1}
				};
	printf("Matrix one\n");
	printMatrix(m1);

	printf("Matrix two\n");
	printMatrix(m2);

	printf("Adding matrix one and two\n");
	addMatrices(m1,m2);

	printf("Multiply matrices one and two\n");
	multiplyMatrices(m1,m2);

	printf("Transpose of matrix one\n");
	transposeMatrix(m1);

	printf("Transpose of matrix two\n");
	transposeMatrix(m2);
}
