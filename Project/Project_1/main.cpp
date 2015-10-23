/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 15, 2015
 * Purpose: Projec 1
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "User.h"

//Constants Variable


//Function Prototypes
User *usCrt(int); // This create player and roll the dice


//Execution Begins Here!!!
int main(int argc, char** argv) {
    
    //Random for the dices
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nUsers; //Number of Users
    string ask; //Ask for number of users
    cout<<"Welcome to the game"<<endl;
    
    //Ask the user for number of users
    do{
        cout<<"How many Users are going to play the game?"<<endl;
        cout<<" (2 (easy) or 3(hard)"<<endl;
        cin>>ask;
        if(ask!="2"&&ask!="3")
            cout<<"Wrong input"<<endl;
    }while(ask!="2"&&ask!="3");
    nUsers=(ask=="2"?2:3);
    

    return 0;
}

