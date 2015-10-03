/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 1, 2015 
 */

//System Libraries
using namespace std;
#include<iostream>
#include<iomanip>

//Function Prototypes
int *sort(int [], int);
int average2(int [], int);

int main(){
 int nScore, average;
 
 cout<<"Input the number of scores to be averaged: \n";
 cin>>nScore;
 
 int *grades = new int[nScore];
 
 for(int i=0;i<nScore;i++)
 {
  cout<<"Input the score "<<i+1<<":\n";
  cin>>grades[i];
  while(grades[i]<0){
   cout<<" Incorrect!"<<endl<<"You can't input negative numbers: \n";
   cin>>grades[i];
  }
 }
 
 grades = sort(grades, nScore);
 
 cout<<"\nThe sorted array of grades: \n";
 for(int i=0;i<nScore;i++)
  cout<<*(grades+i)<< " \n";
 
 average = average2(grades, nScore);
 cout<<"Your final averaged grade is: "<<average<<endl; 
 return 0;
}

int *sort(int grades[], int size)
{
 int mValue, index;
 
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
 }
 return grades;
}
int average2(int grades[], int size)
{
 int count = 0;
 cout<<"\nYour scores and their averages are: \n"
  <<"Score #:"<<setw(10)<<"Score: "<<setw(11)<<"Average: \n";
 for(int i=0;i<size;i++)
 {
  count += *(grades+i);
  cout<<i+1<<setw(15)<<*(grades+i)<<setw(10)<<count / (i+1);
  cout<<endl;
 }
 return (count / size);
}
