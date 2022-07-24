/*This Quick Sort program always uses the last element as the pivot. With minor changes to the partition() function,
random elements or the starting element can also be chosen as the pivot*/
#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void quickSort(int[], int, int);
int partition(int[], int, int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		if (size - i - 1 == 0)
			break;
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	quickSort(arr, 0, size - 1);
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void quickSort(int arr[], int s, int e)
{
	if (s < e)
	{
		int p = partition(arr, s, e);

		quickSort(arr, s, p - 1);		// Don't use the pivot index, use the index one before and one after it
		quickSort(arr, p + 1, e);
	}
}

int partition(int arr[], int s, int e)
{
	int swap, pivot = arr[e], pIndex = s;

	for (int i = s; i < e; i++)
	{
		if (arr[i] <= pivot)
		{
			swap = arr[i];				// First element that is less than the pivot is moved to the first position
			arr[i] = arr[pIndex];
			arr[pIndex] = swap;

			pIndex++;					// Increasing pIndex will cause 2nd, 3rd, etc positions to be occupied by any value that is lower than the pivot
		}
	}

	swap = arr[e];						// Swapping the element at the position just after all the shifted elements with the pivot
	arr[e] = arr[pIndex];
	arr[pIndex] = swap;

	return pIndex;
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}