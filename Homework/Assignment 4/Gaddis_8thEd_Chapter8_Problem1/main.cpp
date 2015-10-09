/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 6, 2015
 * Putpose: Movies
 */

//System Libraries
#include <iostream>
using namespace std;


//User Libraries
struct mveData { //MovieData
    string title; //Movie Title
    string director; //Director of the movie
    int year; //Year Released
    float time; //Running Time
};

//Function Prototypes
void showInfo(mveData);
void showInfo2(mveData);

//Execution Begins Here

int main(int argc, char** argv) {
    mveData movie1 = {"Steve Jobs", "Danny Boyle", 2015, 122};
    mveData movie2 = {"Gone Girl", "David Fincher", 2014, 144};
    
    showInfo(movie1);
    cout<<endl;
    showInfo2(movie2);
   
    return 0;
}
  
void showInfo(mveData p){
//Input the first movie
    cout<< "Title: "<<p.title<<endl;
    cout<< "Director: "<<p.director<<endl;
    cout<< "Year: "<<p.year<<endl;
    cout<< "Running Time: "<<p.time<<" Minutes"<<endl;
}

void showInfo2(mveData p){
//Input the first movie
    cout<< "Title: "<<p.title<<endl;
    cout<< "Director: "<<p.director<<endl;
    cout<< "Year: "<<p.year<<endl;
    cout<< "Running Time: "<<p.time<<" Minutes"<<endl;
}