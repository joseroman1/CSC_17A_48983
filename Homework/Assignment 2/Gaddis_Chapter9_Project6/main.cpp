/* 
 * File:   main.cpp
 * Author: Jose RomaN
 * created on September 23, 2015, 08:45 PM
 * Purpose: Numbers of DNT
 */

using namespace std;
#include<iostream>

// Function prototypes
void arySort(int *[], int);//Array Selection Sort
void sArray(const int [], int);//Show Array
void aryPtr(int *[], int);//Array Pointer

int main()
{
	int nDNT; // Number of donations
	
	cout<<"Please input the number of donations: "<<endl;
	cin>>nDNT;
	
	// An array containing the donation amounts.
	int *DNT = new int[nDNT];
	
	cout<<"\nPlease enter the value of each donation: \n";
	for(int i=0;i<nDNT;i++)
	{
		cout<<"Donation #"<<i+1<<": ";
		cin>>DNT[i];
	}

	// An array of pointers to int.
	int *arrPtr[nDNT];

	// Each element of arrPtr is a pointer to int.
	for (int count = 0; count < nDNT; count++)
		arrPtr[count] = &DNT[count];

	// Sort the elements of the array of pointers.
	arySort(arrPtr, nDNT);

	// Display the donations using the array of pointers. This
	// will display them in sorted order.
	cout << "\nThe donations, sorted in ascending order, are: \n";
	aryPtr(arrPtr, nDNT);

	// Display the donations in their original order.
	cout << "\nThe donations, in their original order, are: \n";
	sArray(DNT, nDNT);
	return 0;
}




void arySort(int *arr[], int size)
{
	int stScan, mIndex;
	int *mElem;

	for (stScan = 0; stScan < (size - 1); stScan++)
	{
		mIndex = stScan;
		mElem = arr[stScan];
		for(int index = stScan + 1; index < size; index++)
		{
			if (*(arr[index]) < *mElem)
			{
			mElem = arr[index];
			mIndex = index;
			}
		}
		arr[mIndex] = arr[stScan];
		arr[stScan] = mElem;
	}
}



void sArray(const int arr[], int size)
{
	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}


void aryPtr(int *arr[], int size)
{
 	for (int count = 0; count < size; count++)
		cout << *(arr[count]) << " ";
	cout << endl;
 }