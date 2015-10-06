/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 5, 2015
 * Purpose: Gaddis Chapter 10 Problem 4
 */

//System Libraries
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wNumber(char *,vector<int> &);//Word number
int wNumber(string,vector<int> &);//Word number

//Execution begins here
int main(int argc, char** argv) {
    char *senten=new char[1000];//sentence with c-string
    //string senten;  //sentence with string
    float average=0;//The average number of letters
    vector<int> lNum;//vector to store the number of letters of each word
    
    cout<<"This program counts the words in a setence..."<<endl;
    cout<<"Please press Enter to continue..."<<endl;
    cin.ignore();
    
    //Ask user for sentence
    cout<<"Please input sentence: "<<endl;
    cin.getline(senten,1000);
    //getline(cin,senten);
    
    //Output 
    cout<<"The number of words in the sentence is "<<wNumber(senten,lNum)<<endl;
    
    //calculate the number of letter
    for(int i=0;i<lNum.size();i++) {
        average+=lNum.at(i);
        //cout<<lNum.at(i)<<" ";
    }
    //get the average 
    average=average/lNum.size();
    cout<<"The average number of letters in each wordin the sentence is "<<average<<endl;
    delete [] senten;
    senten=0;
    
    //Exit stage right
    return 0;
}

//number of words with c-string
int wNumber(char *arr,vector<int> &lNum) {
    int wrdCnt=0;//count of the words
    int ltrCnt=0;//count of number of letters
    bool iWord=false;
    //loop for every letter
    for(int i=0;i<strlen(arr);i++) {
        //if it not space
        if(!isspace(arr[i])) {
            iWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(arr[i])&&iWord) {
            wrdCnt++;
            iWord=false;
            lNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last char is not space, number of word+1
    if(!isspace(arr[strlen(arr)-1])) {
        wrdCnt++; 
        lNum.push_back(ltrCnt);
    }
    return wrdCnt;
}

//number of words with string
int wNumber(string str,vector<int> &lNum) {
    int wrdcnt=0;//count of the words
    int ltrCnt=0;//number of letters in the word
    bool iWord=false;
    //loop for every letter
    for(int i=0;i<str.length();i++) {
        //if it not space
        if(!isspace(str.at(i))) {
            iWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(str.at(i))&&iWord) {
            wrdcnt++;
            iWord=false;
            lNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last character is not space, number of word+1
    if(!isspace(str.at(str.length()-1))) {
        wrdcnt++;    
        lNum.push_back(ltrCnt);
    }
    return wrdcnt;
}