/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 3, 2015
 * Purpose: Gaddis 10.6
 */

//System Libraries
#include <iostream>
#include <string.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int vCount(char *);//Count vowel
int cCount(char *);//Count consonant
//Execution begins here
int main(int argc, char** argv) {
    string answer;//exit or not?
    int crTime=0;//run time
    do {
        if(crTime==0) {
            cout<<"This program counts vowels and consonants.."<<endl;
            cout<<"Press Enter to Continue..."<<endl;
        }
        cin.ignore(1,'\n');
        
        //allocate the dynamic array
        char *arr=new char[1000];//sentence with c-string
        
        //Ask user for sentence
        cout<<"Please input sentence: ";
        cin.getline(arr,1000);
        
        //output the result
        cout<<"The length of the sentence is "<<strlen(arr)<<endl;
        cout<<"The number of vowel is "<<vCount(arr)<<endl;
        cout<<"The number of consonant is "<<csCount(arr)<<endl;
        
        delete [] arr;
        arr=0;
        
        cout<<"Type \"E\" to exit the program, or type anything else for another input"<<endl;
        cin>>answer;
        crTime++;
    } while(answer!="E"&&answer!="e");
    cout<<"you run this program "<<crTime<<" times"<<endl;
    //Exit stage right
    return 0;
}

int vCount(char *arr) {
    int crTime=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
           arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U')  {
            crTime++;
        }
    }
    return crTime;
}

int csCount(char *arr) {
    int crTime=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        //when char is in alphabet
        if(isalpha(arr[i])) {
            if(!(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
               arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'))  {
                crTime++;
            }
        }
    }
    return crTime;
}