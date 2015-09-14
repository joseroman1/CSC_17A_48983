/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Purpose: Review Assignment
 * Modified on September 13th, 2015
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries


//Global Constants

//Function Prototypes
void problem1 ();
void problem2 ();
void problem3 ();
void problem4 ();
void problem5 ();
void problem6 ();
void problem7 ();
void sBoard(char []);
//Problem 6
int cNumber(int [], int);
void printArray(int [],int);
//Problem 7
void delete_repeats(char [],int);
void printAray(char [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare menu variable choice
    char choice;
    //Repeat the menu
    do{
        //General Menu Format
        //Display the selection
        cout<<"Review Assignment Menu."<<endl;
        cout<<"Type 1 to solve Savitch 8th Ed. Chapter 4 Problem 1"<<endl;
        cout<<"Type 2 to solve Gaddis 7th Ed. Chapter 5 Problem 6"<<endl;
        cout<<"Type 3 to solve Gaddis 8th Ed. Chapter 8 Problem 3"<<endl;
        cout<<"Type 4 to solve Gaddis 8th Ed. Chapter 7 Problem 1"<<endl;
        cout<<"Type 5 to solve Savitch 8th Ed. Chapter 7 Problem 10"<<endl;
        cout<<"Type 6 to solve Savitch 9th Ed. Chapter 7 Problem 2"<<endl;
        cout<<"Type 7 to solve Savitch 9th Ed. Chapter 7 Problem 3"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
            case '1':problem1();break;
            case '2':problem2();break;
            case '3':problem3();break;
            case '4':problem4();break;
            case '5':problem4();break;
            case '6':problem4();break;
            case '7':problem4();break;
            default: cout<<"Exit?"<<endl;
        };
    }while(choice>='1'&&choice<='7');
        //Exit right stage
    return 0;
}

//*********** problem 1 **********/
void problem1(){
     //Declare variables
    float L1, W1, L2, W2, A1, A2;
    //Prompt for Input
    cout<<"This program will determine which rectangle has the greater Area."<<endl;
    cout<<"Enter length of First rectangle."<<endl;
    cin>>L1;//Length of first rectangle 
    cout<<"Enter width of First rectangle."<<endl;
    cin>>W1;//Width of first rectangle
    cout<<"Enter length of Second rectangle."<<endl;
    cin>>L2;//Length of Second rectangle
    cout<<"Enter width of Second rectangle."<<endl;
    cin>>W2;//Width of Second rectangle
    
    //Calculate Area
    A1=L1*W1;//Area of first rectangle
    A2=L2*W2;//Area of Second rectangle
    //Output results with IF
    if(A1>A2)
        cout<<"First rectangle has greater area."<<endl;
        else if(A1==A2)
        cout<<"Both rectangles have equal area."<<endl;
        else
        cout<<"Second rectangle has greater area."<<endl;
  
}

//*********** problem 2 **********/
void problem2(){
    //Declare Variable
float Speed,hours,dist;
    cout<<"I will calculate the distance you have traveled. "<<endl;
    cout<<"Enter the speed of your vehicle (in Miles per Hours)"<<endl;
    cin>>Speed;
    cout<<"Then input how many hours you have traveled.(Greater than 1 hour)"<<endl;
    cin>>hours;
    dist=Speed*hours;
    if(Speed<0 || hours<=1)
        cout<<"Error. Please enter positive speeds and greater than or equal to 1."<<endl;
    else{
        cout<<"  Hour     Distance Traveled\n ----------------------------"<<endl;
        for(int x=1;x<=hours;x++){
                dist=Speed*x;
                cout<<"    "<<x<<"\t  "<<setw(10)<<right<<dist<<" miles"<<endl;
        }
    }
}

//*********** problem 3 **********\

void problem3(){
    
    string name[5]; 
int sale[5]; 
int i,hSel=0,hName,lSel=0,lName; 
name[0] = "Mild"; 
name[1] = "Medium"; 
name[2] = "Sweet"; 
name[3] = "Hot"; 
name[4] = "Zesty"; 
int total=0; 
for(i=0;i<=4;i++){ 
cout<<"Enter number of sold "<<name[i]<<" jars: "; 
cin>>sale[i]; 
total = total + sale[i]; 
    if(i==0){
        hSel=sale[i];
        hName=i;lSel=sale[i];
        lName = i;
         }if(hSel<sale[i]){
             hSel=sale[i];
             hName=i;
             }if(lSel>sale[i]){
                 lSel=sale[i];
                 lName=i; } 
}
cout<<"There were sold:  "<<endl; 
for(i=0;i<=4;i++){ 
cout<<sale[i]<<" "<<name[i]<<" jars"<<""<<endl; 
} 
cout<<"Total sales: "<<total<<" jars"<<endl; 
cout<<"Highest sales: "<<hSel<<" ("<<name[hName]<<" salsa)"<<endl; 
cout<<"Lowest sales: "<<lSel<<" ("<<name[lName]<<" salsa)"<<endl;
    }

//************** Problem 4 ***********/
void problem4(){
    //Declare variables
    const int SIZE=10;
    int a[SIZE];
    int min,max;
    //Prompt user
    cout<<"Input 10 random numbers. Press return after entering each number."<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];//User input
    }
    min=a[0];
    max=a[0];
    //Finding the max and minimum of the input
    for(int i=1;i<10;i++){
        if(min>a[i]){
            min=a[i];
        }else if(max<a[i]){
            max=a[i];
        }
    }
    //Output the results
    cout<<"Min "<<min<<endl;
    cout<<"Max "<<max<<endl;
    
                }
                
//************** Problem 5 ***********/
void problem5(){
     const char SIZE=9;
    char board[SIZE];
    int nMoves = 0;
    char wTurn = 'X';
    int move;
    for (int i=0;i<9;i++){
        board[i]= '1' + i;
    }
    while (nMoves < 9){
        sBoard(board);
        cout<<"Enter move: "<<endl;
        cin>>move;
        if((move < 1) || (move > 9))
            cout<<"Invalid move, try again"<<endl;
        else{
            move--;
            if ((board[move]=='X') || (board[move]=='O'))
                cout<<"That space is taken. "<<endl;
            else{
                board[move]= wTurn;
                //Switch turn
                if(wTurn == 'X')
                    wTurn = 'O';
                else
                    wTurn = 'X';
                    nMoves++;
                
            }
        }
    }
//Display Board
        sBoard(board);
        cout<<endl<<"Game over.."<<endl;
        
    
}
void sBoard(char board[]){
    cout<<endl;
    for (int i=0;i<9;i++){
        cout<<board[i]<<" ";
        if (((i+1) % 3) == 0)cout<<endl;
        
    }
    cout<<endl;
}
   
 //************** Problem 6 ***********/              
void problem6(){
     //Declare Variables
    int SIZE = 5;
    int array[SIZE];
    int nof2 = 0;//Number of two
    
    cout<<"Give me "<<SIZE<<" Numbers. Press Return after entering each number"<<endl;
    cin>>array[0]>>array[1]>>array[2]>>array[3]>>array[4];
    
    //Print array
    printArray (array, SIZE);
    
    //Count the number of two
    nof2 = cNumber(array, SIZE);
    cout<<"The number of 2's in the array is : "<<nof2<<endl;
    
}

void printArray(int a[],int SIZE){
    for(int i=0;i<SIZE;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int cNumber(int a[],int SIZE){
    int counter =0;
    for (int i=0;i<SIZE;i++){
        if(a[i] == 2)
            counter++;
    }
    return counter;
    
}
//************** Problem 7 ***********/              
void problem7(){
    char SIZE=10;
    char array[SIZE];
    array[0] = 'a';  
    array[1] = 'b';
    array[2] = 'a';
    array[3] = 'c';
    int sizes = 4;
    cout<<"Before removing: ";
    printAray(array,sizes);
    delete_repeats(array,sizes);
    cout<<"After removing: ";
    printAray(array,sizes);

}
void printAray(char a[],int sizes){
    for(int i=0;i<sizes;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void delete_repeats(char a[],int sizes){
//Go through and find the repeated characters
for(int i=0;i<sizes;i++){
    for(int j=i+1;j<sizes;j++){
        //.if the character is repeated
        if(a[i] == a[j])
            a[j]= 0;
        else 
            continue;
    }
}
 //Go throught and find the deleted character
for(int i = 0;i<sizes;i++){
    //empty space move it forward
    if(a[i] == 0){
        a[i] = a[i+1];
        a[i+1] = 0;
    }
    else
        continue;
}
}
    