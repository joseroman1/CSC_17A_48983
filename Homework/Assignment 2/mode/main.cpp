/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on September 25, 2015
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries

//Function Prototypes
float mean(int [], int);
float median(int [], int);
int *mode(int [], int);
void cap(int [], int);
void FillAry(int [], int);
int sizeAry(int [], int);

//Execution Begins Here
int main(int argc, char** argv) {
    srand(time (0));
    int size;
    cout << "Input the number of the sixe of the array?"<<endl;
    cin >> size;
    int array[size]; 
    FillAry(array, size);
    cout << "The array is filled with random one digit numbers: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cap(array, size);
    cout << "The array is now sorted: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "The mean of the array is: ";
    cout << mean(array, size) << endl;
    cout << "The median of the array is: ";
    cout << median(array, size) << endl;
    int newSize = sizeAry(array, size);
    int *arry2 = mode(array, size);
    cout << "The mode is done in a dynamic array, where the first position "
            << "is the mode, the second position is the frequency, and "
            << "the last positions are which numbers are the mode " << endl;
    for(int i = 0; i < newSize + 2; i++)
    {
        cout << arry2[i] << " ";
    }
    delete []arry2;
    return 0;
}

void FillAry(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i] = rand()%9+1;
    }
}

void cap(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

float mean(int a[], int size)
{
    float average;
    for(int i = 0; i < size; i++)
    {
        average += a[i];
    }
    average/= size;
    return average;
}

float median(int a[], int size)
{
    float middle = 0;
    if(size % 2 == 0)
    {
        middle = (a[(size/2)-1] + a[size/2]); 
        return middle / 2;
    }
    else
    {
        middle = a[size/2];
        return middle;
    }
}

int *mode(int array[], int size)
{
    //freq is for the frequency
    //fiFre is to find the frequency
    //nOfMo is to find the number of modes
    //lOfMo if for the location of the mode
    int fiFre = 1, freq = 1, lOfMo = 0, nOfMo  = 0;
    //this for loop is to find the mode
    for(int i = 0; i < size; i++)
    {
        if(array[i] == array[i+1])
        {
            fiFre++;
            if(fiFre >= freq)
            {
                freq = fiFre;
            }
        }
        else if(array[i] != array[i+1])
        {
            fiFre = 1;
        }
    }
    fiFre = 1;
    //for loop is to find how many modes
    for(int i = 0; i < size; i++)
    {
        if(array[i] == array[i+1])
        {
            fiFre++;
            if(fiFre == freq)
            {
                nOfMo ++;
            }
        }
        else
        {
            fiFre = 1;
        }
    }
    //arry2 is the dynamic array and the size is 2 plus all the mode numbers
    int *arry2 = new int[2+nOfMo ];
    arry2[0] = freq;
    arry2[1] = nOfMo ;
    int cArray = 0;
    //for loop is to find the location of the modes
    for(int i = 0; i < size; i++)
    {
        if(array[i] == array[i+1])
        {
            fiFre++;
            if(fiFre == freq)
            {
                lOfMo = array[i];
                arry2[cArray+2] = lOfMo;
                cArray++;
            }
        }
        else
        {
            fiFre = 1;
        }
    }
    return arry2;
}

int sizeAry(int array[], int size)
{
    int fiFre = 1, freq = 1, nOfMo  = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i] == array[i+1])
        {
            fiFre++;
            if(fiFre >= freq)
            {
                freq = fiFre;
            }
        }
        else if(array[i] != array[i+1])
        {
            fiFre = 1;
        }
    }
    fiFre = 1;
    for(int i = 0; i < size; i++)
    {
        if(array[i] == array [i+1])
        {
            fiFre++;
            if(fiFre == freq)
            {
                nOfMo ++;
            }
        }
        else
        {
            fiFre = 1;
        }
    }
    return nOfMo ;
}