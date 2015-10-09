/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 6, 2015
 * Putpose: Movies Profits
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
    float cost; //Movie Production Cost
    float revenue; //First Year Revenue
    float profit; //Calculate profits
};

//Function Prototypes
void showInfo(mveData);
void showInfo2(mveData);

//Execution Begins Here

int main(int argc, char** argv) {
    mveData movie1 = {"Steve Jobs", "Danny Boyle", 2015, 122, 3.5e7, 3.65e8};
    mveData movie2 = {"Gone Girl", "David Fincher", 2014, 144, 6.1e7, 3.68e8};
    
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
    cout<< "Profit: "<<p.revenue - p.cost<<endl;
}

void showInfo2(mveData p){
//Input the first movie
    cout<< "Title: "<<p.title<<endl;
    cout<< "Director: "<<p.director<<endl;
    cout<< "Year: "<<p.year<<endl;
    cout<< "Running Time: "<<p.time<<" Minutes"<<endl;
    cout<< "Profit: "<<p.revenue - p.cost<<endl;
}