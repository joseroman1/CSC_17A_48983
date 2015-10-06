/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 2, 2015
 */

//system libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//global Constants

//Function Prototypes
void aryFile(string,int *,int);
void fileAry(string,int *,int);
int *fillAry(int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int size;
    string fileNam;//file name
    do {
        cout<<"Size of array (1-9): "<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
   
    cout<<"File name (file1.txt): "<<endl;
    cin>>fileNam;
       
    //allocate the memory
    int *arr=fillAry(size);
    int *arrIn=new int[size];
    
    //output the array
    cout<<"Before writing to file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    cout<<endl<<endl;;
    
    aryFile(fileNam,arr,size);//write the array to file
    fileAry(fileNam,arrIn,size);//get the array from the file
    
    cout<<"Read the array from the file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arrIn[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    //deallocate memory
    delete arr;
    delete arrIn;
    //Exit stage right
    return 0;
}

int *fillAry(int n) {
    int *arr=new int[n];
    for(int i=0;i<n;i++) {
        arr[i]=rand()%90+10;
    }
    return arr;
}

void aryFile(string fileNam,int *a,int n) {
    fstream file;
    file.open(fileNam,ios::out|ios::binary);
    if(!file.fail())
        file.write(reinterpret_cast<char *>(a),sizeof(int)*n);
    file.close();
}

void fileAry(string fileNam,int *a,int n) {
    fstream file;
    file.open(fileNam,ios::in|ios::binary);
    if(!file.fail()) {
        file.read(reinterpret_cast<char *>(a),sizeof(int)*n);
    }
    
    file.close();
}