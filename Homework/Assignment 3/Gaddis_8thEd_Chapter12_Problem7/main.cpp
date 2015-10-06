/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 5, 2015
 * Purpose: Gaddis chapter 12 problem 7
 */

//system libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    ifstream input;
    ofstream output;
    string inFileN;//input file name
    string otFileN;//output file name
    char ch;
    int count=0;
    //get the input file name
    cout<<"Enter the input file  (input.txt): ";
    cin>>inFileN;
    //get the output file name
    cout<<"Enter the output file (out.txt): ";
    cin>>otFileN;
    cout<<"Now, open the file..."<<endl;
    input.open(inFileN);//open the input file
    if(!input.fail()) { //if open successfully
        cout<<"Opening the input file was successfully"<<endl;
        output.open(otFileN);
        if(!output.fail()) {
            cout<<"Opening the output file was successfully"<<endl;
            input.get(ch);
            while(input) {
                if(count==0) output.put(toupper(ch)); 
                else    output.put(tolower(ch));
                count++;
                if(ch=='.') count=0;
                input.get(ch);
                
            }
            cout<<"The sentence was converted to lower case to the output file"<<endl;
        } else { //if it's fail to open output file
            cout<<"Cannot open the output file"<<endl;
        }
    } else { //if fail to open input file
        cout<<"Cannot open the input file"<<endl;
    }
    input.close();
    output.close();
    //Exit stage right
    return 0;
}