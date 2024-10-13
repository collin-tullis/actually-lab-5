#include <stdio.h>
#include <stdlib.h>

// displays the monthly sales reports
void printMonthSales(double sales[])
{
	const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for(int i = 0; i < 12; i++)
	{
		printf("%-10s: $%.2f\n", months[i], sales[i]);
	}
}

// displays the min, max, average
void printSalesSum(double sales[])
{
	double min = sales[0], max = sales[0], sum = 0;

	for(int i = 0; i < 12; i++)
	{
		if(sales[i] < min)
		{
			min = sales[i];
		}
		if(sales[i] > max)
		{
			max = sales[i];
		}
		sum += sales[i];
	}
	double average = sum / 12;
	printf("Minimum Sales: $%.2f\n", min);
	printf("Maximum Sales: $%.2f\n", max);
	printf("Average Sales: $%.2f\n", average);
}

// displays six month moving average
void printSixMonth(double sales[])
{
	for(int i = 0; i <= 6; i++)
	{
		double sum = 0;
		for(int j = 1; j < i; j++)
		{
			sum += sales[j];
		}
		double average = sum / 6;
		printf("Month %d-%d: $%.2f\n", i+1, i+6, average);
	}
}


// displays sales highest to lowest
void printSalesSorted(double sales[])
{
	double sortedSales[12];
	const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	//copys the sales over
	for(int i = 0; i < 12; i++)
	{
		sortedSales[i] = sales[i];
	}
	//sorts the sales
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 11 - i; j++)
		{
			if(sortedSales[j] < sortedSales[j+1])
			{
				double temp = sortedSales[j];
				sortedSales[j] = sortedSales[j+1];
				sortedSales[j+1] = temp;
			}
		}
	}

	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(sortedSales[i] == sales[j])
			{
				printf("%-10s: $%.2f\n", months[j], sortedSales[i]);
				break;
			}
		}
	}
	
}

int main()
{
	double sales[12];
	FILE *file;
	
	//open file
	file = fopen("sales.txt", "r");
	if(file == NULL)
	{
		printf("File not found.");
		return 1;
	}
	
	//read file
	for(int i = 0; i < 12; i++)
	{
		if(fscanf(file, "%lf", &sales[i]) != 1)
		{
			printf("File not in correct format");
			fclose(file);
			return 1;
		}
	}
	
	fclose(file);

	//print things
	printf("1. Monthly Sales Report:\n");
	printMonthSales(sales);

	printf("\n2. Sales Summary Report:\n");
	printSalesSum(sales);

	printf("\n3. Six Month Moving Average Report\n");
	printSixMonth(sales);

	printf("\n4. Sales Report High to Low\n");
	printSalesSorted(sales);

	return 0;

}

















