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
#include <vector>
using namespace std;

//User Libraries
#include "User.h"

//Constants Variable


//Function Prototypes
User *usCrt(int);//This create player and rool the dice
char *rDice(int);//5 Dices
void dDice(User *);//Output dice of an user
void chlg(User,int &,int);//User challenge
void bidding(User &,char &,int &,int,int &,int,bool &);//User 1 is first
void cBidding(int,User &,char &,int &,int &,bool);//Computer turn
void cChlg(int &,User,char,int,int,int,bool);//Computer challenge
int gQnty(User,char,bool);//This get the quantity
vector<char> gNEx(char *);//Dices that not exist 
vector<char> gEx(char *);//Dices that exist 
char gFreq(char *);//Frequent of dice 
void rstl(int,char,int,User *,int,bool);//Who win and lost
void file(User *,int);//User resuls into file
void dFile(User *,int);//Output the file

//Execution begins here
int main(int argc, char** argv) {
   //Random for the dcs
    srand(static_cast<unsigned int>(time(0)));
  
   //Declare Variables
    int nUsers;// Number of users
    int rGame=0;//The round of the game
    int opn=-1;
    bool wld = true;//1 is wld, when after bidding 1s or bidding only 3 5s,then 1 is not wld
    string ask;//Ask for input
    
    //Ask the user for number of users
     cout<<"Welcome to the Dice Game"<<endl<<endl;
     do{
        cout<<"How many users are going to play the game?"<<endl;
        cout<<" (2 (easy) or 3(hard)"<<endl;
        cin>>ask;
        if(ask!="2"&&ask!="3")
            cout<<"Wrong input"<<endl;
    }while(ask!="2"&&ask!="3");
    nUsers=(ask=="2"?2:3);

    //Create the user and the dice
    User *users=usCrt(nUsers);
    User *rFile=new User[nUsers];//Reading file
    file(users,nUsers);//Users into file
    
   //Initial based on the number of Users
    char value='0';//initial the value to 0
    int number=nUsers*3/2;//Initial the number to 1.5*number of user
    dDice(users);//Output your dice
    
   //Game Runs
    int temp=rand()%nUsers;//Random select who is the first to bidding
    //Run until somebody challenge
    do {
        switch(temp) {
            case 0: {
                chlg(users[0],opn,rGame);//User challenge
                if(nUsers==3) cChlg(opn,users[1],value,number,nUsers,rGame,wld);//Computer #2 challenge
                bidding(users[0],value,number,nUsers,rGame,opn,wld);//User bidding
            }
            case 1: {
                cChlg(opn,users[1],value,number,nUsers,rGame,wld);//Computer number 1 challenge
                if(nUsers==3) cChlg(opn,users[2],value,number,nUsers,rGame,wld);// Computer Two challenge
                cBidding(opn,users[1],value,number,rGame,wld);//Computer First bidding
            }
            case 2: {
                if(nUsers==3) {
                    chlg(users[0],opn,rGame);//User challenge
                    cChlg(opn,users[2],value,number,nUsers,rGame,wld);//Computer 2 challenge
                    cBidding(opn,users[2],value,number,rGame,wld);//Computer 2 bidding
                }
            }
        }
        temp=0;
    } while(opn==-1);
    //Read file(users)
    dFile(rFile,nUsers);
    //Output the dice of all users
    for(int i=0;i<nUsers;i++) {
        dDice(rFile+i);
    } 
    //Output the resutlt of the game
    rstl(number,value,nUsers,rFile,opn,wld);
    //Deallocate memory
    for(int i=0;i<nUsers;i++) {
        //Delete []rFile[i].dice;
        delete []users[i].dice;
    }
    delete []users;
    delete []rFile;
    //Exit stage right
    return 0;
}

void file(User *w,int o) {
    fstream oFile;
    cout<<"Writing to the file"<<endl;
    oFile.open("user.txt",ios::out|ios::binary);
    if(!oFile.fail()) {
       oFile.write(reinterpret_cast<char *>(w),sizeof(User)*o); 
    }
    oFile.close();
}

void dFile(User *p,int q) {
    fstream in;
    cout<<"Read from the file..."<<endl<<endl;
    in.open("users.txt",ios::in|ios::binary);
    if(!in.fail()) {
       in.read(reinterpret_cast<char *>(p),sizeof(User)*q); 
    }
    in.close();
}

//Create users and dice
User *usCrt(int e) {
    User *users=new User[e];
    for(int i=0;i<e;i++) {
        users[i].dice=rDice(5);
        users[i].oGame=i;
    }
    return users;
}

//This roll the dice and save an array
char *rDice(int e) {
    //allocate memory
    char *dice=new char[e];
    //Random the roll the dice
    for(int i=0;i<e;i++) {
        dice[i]=static_cast<char>(rand()%6+1+48);
    }
    return dice;
}

//Output the dice of an user
void dDice(User *w) {
    if(w->oGame==0) cout<<endl<<"Your    ";
    else cout<<"Computer Number"<<w->oGame<<"'s ";
    cout<<"dice: ";
    for(int i=0;i<5;i++) {
        cout<<w->dice[i]<<" ";
    }
    cout<<endl;
}

void chlg(User w,int &opn,int v) {
    string input="N";//Input of opn or not
    //Ask user for challenge or not
    if(v!=0&&opn==-1) {
        do {
            cout<<"Would you like to challenge?(Y or N): ";
            cin>>input;
            if(input!="Y"&&input!="N"&&input!="y"&&input!="n") 
                cout<<"Wrong Input"<<endl;
        } while(input!="Y"&&input!="N"&&input!="y"&&input!="n");
    }
    //Input is opn
    if(input=="Y"||input=="y") {
        opn=w.oGame; // opn to true
        cout<<"You Challenge"<<endl;
    }
}

void bidding(User &w,char &value,int &number,int nUsers,int &v,int opn,bool &g) {
    string bidding;
    int nTemp;
    char vTemp;
    bool nC;
    //Input is opn
    if(opn==-1) { //Input is not opn
        cin.ignore();
        do {
            nTemp=0;
            vTemp=' ';
            nC=false;
            if(v<=2) {
            cout<<"Your bidding: ";
            cout<<"Format:\"3 4\"(means you bidding 3 4s,and 1s are wld) or \"4n5\"(means you bidding 4 5s only, and 1s are not wild)"<<endl;
            cout<<"First bidding must be >= 1.5*users"<<endl;
            }
            cout<<"Your bidding: ";
            getline(cin,bidding);
         //Is input valid or not
            if(bidding.length()!=3&&bidding.length()!=4) nC=true;
            if(bidding.length()==3||bidding.length()==4) {
                for(int i=0;i<bidding.length();i++) {  
                    if(i==bidding.length()-2) {
                        if(bidding.at(i)!=' '&&bidding.at(i)!='n'&&bidding.at(i)!='N') nC=true;
                    }
                    if(i<bidding.length()-2) 
                   if(bidding.at(i)<'0'||bidding.at(i)>'9') nC=true;
                    if(i>bidding.length()-2) 
                    if(bidding.at(i)<'1'||bidding.at(i)>'6') nC=true;
                }
            }
            if(!nC) {
                if(bidding.length()==3) {
                    nTemp=static_cast<int>(bidding.at(0)-48);
                    vTemp=bidding.at(2);
                } else if(bidding.length()==4) {
                    nTemp=static_cast<int>(bidding.at(0)-48)*10+static_cast<int>(bidding.at(1)-48);
                    vTemp=bidding.at(3);
                }
            }
            //if format of ask is right, check the contents of ask
            if(nTemp<number) nC=true; //quantity less than previous one
            //quantity=previous one,but value of dice< previous one
            if(nTemp==number&&vTemp<=value) nC=true;
            if(nTemp>nUsers*5) nC=true;
            if(nC) cout<<"Wrong Input.."<<endl;
        } while(nC);
        
        number=nTemp;
        value=vTemp;
        if(bidding.at(bidding.length()-2)=='n'||bidding.at(bidding.length()-2)=='N') g=false;
        if(bidding.at(bidding.length()-1)=='1') g=false;
        cout<<"You bidding "<<number<<"  "<<value<<"s";
        if(g) cout<<" "<<endl;
        else cout<<" only"<<endl;
        v++;
    }
}
