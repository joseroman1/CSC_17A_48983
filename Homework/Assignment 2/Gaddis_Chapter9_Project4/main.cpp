/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on September 27, 2015
 * Purpose: Calculated Scores
 */

//System Libraries
using namespace std;
#include<iostream>
#include<iomanip>
#include<string.h>

//Function Prototypes
void sort(int [],string[], int);

//Execution Begins Here!
int main()
{
 int nScore;
 
 
 cout<<"Input the number of students and scores to calculate: "<<endl;
 cin>>nScore;
 
 int *grades = new int[nScore];
 string *names = new string[nScore];
 
 for(int i=0;i<nScore;i++)
 {
  cin.ignore();
  cout<<"\nInput the name of student "<<i+1<<":\n";
  getline(cin, *(names+i));
  cout<<"Please input score "<<i+1<<":\n";
  cin>>grades[i];
  while(grades[i]<0){
   cout<<"Incorrect"<<endl<<"You can't Input a negative value: \n";
   cin>>grades[i];
  }
  
 }
 
 sort(grades, names, nScore);
 
 cout<<"\nThe sorted array of grades and names: \n";
 for(int i=0;i<nScore;i++){
  cout<<*(names+i)<<setw(30)<<*(grades+i)<<endl;
 }
  
 return 0;
}

void sort(int grades[], string names[], int size)
{
 int mValue, index;
 string swap;
 
 for(int i=0;i<size-1;i++)
 {
  index=i;
  mValue=grades[i];
  for(int j=i+1;j<size;j++)
  {
   if(grades[j] < mValue)
   {
    mValue=grades[j];
    index=j;
   }
  }
  grades[index]=grades[i];
  grades[i]=mValue;
  swap=names[index];
  names[index]=names[i];
  names[i]=swap;  
 }
}
