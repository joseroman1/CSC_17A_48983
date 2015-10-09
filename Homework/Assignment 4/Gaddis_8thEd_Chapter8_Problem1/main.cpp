/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 6, 2015
 * Putpose: Movies
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;


//User Libraries
struct mveData { //MovieData
    string title; //Movie Title
    string director; //Director of the movie
    int year; //Year Released
    float time; //Running Time
};
int main(int argc, char** argv) {
    mveData movie1 = {"Steve Jobs", "Danny Boyle", 2015, 122};
    mveData movie2 = {"Gone Girl", "David Fincher", 2014, 144};
    
    cout<< fixed << showpoint << setprecision(2);
    
    //Input the first movie
    cout<< "Title: "<<movie1.title<<endl;

    return 0;
}

