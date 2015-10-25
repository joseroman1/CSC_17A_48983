/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 15, 2015
 * Purpose: Projec 1
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries
#include "User.h"

//Constants Variable


//Function Prototypes
User *usCrt(int); // This create player and roll the dice
void file(User *, int);//File
void dFile(User*,int);//Read the file
void dDice(User *);
void chlg(User,int &,int);
void AIChlg(int &, User,char,int,int,int,bool);//Computer Challenge
void bidding(User &,char &,int &,int,int &,int,bool &);//First User
void AIBidding(int,User &,char &,int &,int &,bool);//Computer's turn
void rstl(int,char,int,User *,int,bool);// who win and lost




//Execution Begins Here!!!
int main(int argc, char** argv) {
    //Random for the dcs
    srand(static_cast<unsigned int>(time(0)));
    
  //Declare Variables
    int nUsers;//number of player
    int rGame=  0;//The rounds of the game
    int opn = -1; //opn=-1 -> not opn; =0 -> player1 opn; =1 -> player2 opn etc.
    bool wld= true;//1 is wild, when after bidding 1s or bidding only 3 5s,then 1 is not wild
    string ask;//Asl for number for users

  //Ask the user for number of users 
    cout<<"Welcome to the Dice Game"<<endl;
 do{
        cout<<"How many users are going to play the game?"<<endl;
        cout<<" (2 (easy) or 3(hard)"<<endl;
        cin>>ask;
        if(ask!="2"&&ask!="3")
            cout<<"Wrong input"<<endl;
    }while(ask!="2"&&ask!="3");
    nUsers=(ask=="2"?2:3);

//Create the user and the dcs
    User *user = usCrt(nUsers);
    User *rFile = new User[nUsers];
    file(user,nUsers);
   
//Initial based on the number of player
    char value = '0';// initial the value to 0
    int number =  nUsers*3/2; //initial the number to 1.5*number of player
    dDice(user);//display your dice
    
//Game Runs
    int temp=rand()%nUsers;//random select who is the first to bidding
    //Run until somebody challenge
    do {
        switch(temp) {
            case 0: {
                chlg(user[0],opn,rGame);//player challenge
                if(nUsers==3) AIChlg(opn,user[1],value,number,nUsers,rGame,wld);//AI #2 challenge
                bidding(user[0],value,number,nUsers,rGame,opn,wld);//player bidding
            }
            case 1: {
                AIChlg(opn,user[1],value,number,nUsers,rGame,wld);//AI #1 challenge
                if(nUsers==3) AIChlg(opn,user[2],value,number,nUsers,rGame,wld);//AI #2 challenge
                AIBidding(opn,user[1],value,number,rGame,wld);//AI #1 bidding
            }
            case 2: {
                if(nUsers==3) {
                    chlg(user[0],opn,rGame);//Player challenge
                    AIChlg(opn,user[2],value,number,nUsers,rGame,wld);//AI #2 challenge
                    AIBidding(opn,user[2],value,number,rGame,wld);//AI #2 bidding
                }
            }
        }
        temp=0;
    } while(opn==-1);
    //read the binary file(user)
    dFile(rFile,nUsers);
    //show dcs of all user
    for(int i=0;i<nUsers;i++) {
        dDice(rFile+i);
    } 
    //Output the results of the game
    rstl(number,value,nUsers,rFile,opn,wld);
    //deallocate memory
    for(int i=0;i<nUsers;i++) {
        //delete []rFile[i].dice;
        delete []user[i].dice;
    }
    delete []user;
    delete []rFile;
    //Exit stage right
    
    return 0;
}

void file(User* w,int o){
    fstream oFile;
    cout<<"Writing to the file"<<endl;
    oFile.open("user.txt",ios::out|ios::binary);
    if(!oFile.fail()){
      oFile.write(reinterpret_cast<char *>(w),sizeof(User)*o);
    }
    oFile.close();
    
}