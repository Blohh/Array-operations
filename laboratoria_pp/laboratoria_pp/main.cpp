#include <iostream>

using namespace std;

const int SIZE_OF_TABLE = 13; //maximal table size

//read integer and return it
int readInteger()
{
	int value = 0;
	 cin >> value;
	 return value;
}
//checks if table is empty
bool isTableEmpty(int actual_table_size)
{
	if (actual_table_size == 0) return true;
	else return false;
}
//checks if table is full
bool isTableFull(int actual_table_size)
{
	if (actual_table_size == SIZE_OF_TABLE) return true;
	return false;
}
//add a number n to the array after the last one added by this command. Start from the beginning of the array. 
void insertIntegerToTable(int *actual_table_size, int tab[], int n)
{
	tab[(*actual_table_size)++] = n;
}
//add a number n to the array if it is not full. Inform the user when the array is full.
void insertIntegerTotableIfItIsNotFull(int *actual_table_size, int tab[], int n)
{
	if (isTableFull(*actual_table_size)) cout << "[WARNING] TABLE IS FULL!\n";
	else insertIntegerToTable(actual_table_size, tab, n);
}
//print elements stored under the indices in range from a to b. Print how many elements of the array were omitted.
void printElemtsInRangeFromAToB(int *actual_table_size, int tab[], int a, int b)
{
	for (int i = a; i <= b; i++)
		cout << tab[i] << " ";
	cout << endl << "Omitted: " << *actual_table_size - b + a - 1 << " values" << endl;
}
//checks if table is not empty and correctivity of values a, b and prints elements or information about incorrect index and empty table
void printElementsInRangeFromAToBIfItIsPossible(int *actual_table_size, int tab[], int a, int b)
{
	if(isTableEmpty(*actual_table_size)) cout << "[INFORMATION] TABLE IS EMPTY!\n"; //check if table is empty
	else if (a >= 0 && b < *actual_table_size && a < b) printElemtsInRangeFromAToB(actual_table_size, tab, a, b);
	else cout << "[WARNING] INCORRECT INDEX VALUE!\n";
}
//print every i-th elements stored in the array. Eg. i=2 prints every second element, i=1 writes every element.
void printIthElements(int *actual_table_size, int tab[], int i)
{
	for (int j = 0; j < *actual_table_size; j += i)
		cout << tab[j] << " ";
	cout << endl;
}
//checks if table is not empty and index is correct, if not print information, if is correct print every ith element of table
void printIthElementsIfItIsPossible(int *actual_table_size, int tab[], int i)
{
	if (isTableEmpty(*actual_table_size)) cout << "[INFORMATION] TABLE IS EMPTY!\n";
	else if (i >= 0) printIthElements(actual_table_size, tab, i);
	else cout << "[WARNING] INNCORRECT INPUT DATA!\n";
}
//return largest element of table
int findLargestlValueOfTable(int actual_table_size, int tab[])
{
	int max = 0;
	for (int i = 0; i < actual_table_size; i++)
		if (tab[i] > max)
			max = tab[i];
	return max;
}
//return lowest element of table
int findLowestValueOfTable(int actual_table_size, int tab[])
{
	int min = findLargestlValueOfTable(actual_table_size, tab);
	for (int i = 0; i < actual_table_size; i++)
		if (tab[i] < min)
			min = tab[i];
	return min;
}
//return second lowest element of table
int findSecondLowestElementOfTable(int actual_table_size, int tab[], int min)
{
	int min2 = findLargestlValueOfTable(actual_table_size, tab);
	for (int i = 0; i < actual_table_size; i++)
	{
		if (tab[i] < min2 && tab[i] != min)
			min2 = tab[i];
	}
	return min2;
}
//print two elements of table
void printTwoLowestElementsOfTable(int actual_table_size, int tab[])
{
	int min1 = findLowestValueOfTable(actual_table_size, tab), min2 = findSecondLowestElementOfTable(actual_table_size, tab, min1);
	cout << min1 << " " << min2 << endl;
}
//print two lowest elements of table if it is not empty
void printTwoLowestElementsOfTableIfItIsNotEmpty(int actual_table_size, int tab[])
{
	if (isTableEmpty(actual_table_size)) cout << "[INFORMATION] TABLE IS EMPTY!\n";
	else printTwoLowestElementsOfTable(actual_table_size, tab);
}
/*program controller 
-- A n		-- adds value n at end of table 
-- R a b	-- prints elements in range from a to b
-- P i		-- prints every ith element of table
-- M		-- prints two lowest elements of table
-- Q		-- quit program
*/
void controller(char command, int *actual_table_size, int tab[])
{
	int n = 0, a = 0, b = 0, i = 0;
	switch (command)
	{
	case 'A': 
		n = readInteger();
		insertIntegerTotableIfItIsNotFull(actual_table_size, tab, n);
		break;
	case 'R': 
		a = readInteger(), b = readInteger();
		printElementsInRangeFromAToBIfItIsPossible(actual_table_size, tab, a, b);
		break;
	case 'P': 
		i = readInteger();
		printIthElementsIfItIsPossible(actual_table_size, tab, i);
		break;
	case 'M':
		printTwoLowestElementsOfTableIfItIsNotEmpty(*actual_table_size, tab);
		break;
	case 'Q':
		exit(0);
	}
}
int main()
{
	char command;
	int tab[SIZE_OF_TABLE];
	int actual_table_size = 0;
	while (true)
	{
		cin >> command;
		controller(command, &actual_table_size, tab);
	}
	return 0;
}