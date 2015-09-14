/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  To Illustrate the code for
 * developing a menu
 * Problem 1 -> Sum the numbers between 1 and 10
 * Problem 2 -> Multiply the numbers between 1 and 10
 * Problem 3 -> Divide the numbers between 1 and 10
 * Modified on Apr 6th, 2015
 *      Add repetition with a do-loop
 */

//System Libraries
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

//User Libraries


//Global Constants
const float LGAL=0.264179;//Liters per gallon

//Function Prototypes
void problem1 ();
void problem2 ();
void problem3 ();
void problem4 ();
 float fnMPG(float,float);
 float fnMPG2(float,float);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare menu variable choice
    char choice;
    //Repeat the menu
    do{
        //General Menu Format
        //Display the selection
        cout<<"Chapter 4 Homework Assignment Menu."<<endl;
        cout<<"Type 1 to solve Savitch 8th Ed. Chapter 4 Problem 1"<<endl;
        cout<<"Type 2 to solve Savitch 8th Ed. Chapter 4 Problem 2"<<endl;
        cout<<"Type 3 to solve Savitch 8th Ed. Chapter 4 Problem 15 "<<endl;
        cout<<"Type 4 to Savitch 8th Ed. Chapter 4 Problem 15"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
            case '1':problem1();break;
            case '2':problem2();break;
            case '3':problem3();break;
            case '4':problem4();break;
            default: cout<<"Exit?"<<endl;
        };
    }while(choice>='1'&&choice<='3');
        //Exit right stage
    return 0;
}

//*********** problem 1 **********/
void problem1(){
    
  
}

//*********** problem 2 **********/
void problem2(){

}

//*********** problem 3 **********\

void problem3(){
    
    
    }

//************** Problem 4 ***********/
void problem4(){
    
                }
                
