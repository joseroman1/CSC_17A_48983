/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 15, 2015
 * Purpose: Projec 1
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

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
    in.open("user.txt",ios::in|ios::binary);
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

void cChlg(int &opn,User w,char value,int number,int nUsers,int v,bool g) {
    if(v!=0&&opn==-1) {
        //This determine challenge or not
        if(g) {
            if(gQnty(w,value,g)>=number) opn=-1; //Bided number of a kind dice <= Computer's, not challenge 
            else if(gQnty(w,value,g)==0&&number>=nUsers*2) opn=w.oGame;
            else if(gQnty(w,value,g)==1&&number-1>(nUsers-1)*2) {
                if(rand()%6<3) opn=w.oGame; 
            } else if(gQnty(w,value,g)==2&&number-2>(nUsers-1)*2) {
                if(rand()%6<2) opn=w.oGame; 
            } else if(gQnty(w,value,g)==3&&number-3>(nUsers-1)*2) {
                if(rand()%6<2) opn=w.oGame; 
            } else if(gQnty(w,value,g)>=4&&number-gQnty(w,value,g)>(nUsers-1)*2) {
                opn=w.oGame; 
            }
            if(number>=nUsers*3) {
                if(number>=nUsers*4) opn=w.oGame;
                else {
                    if(rand()%5<4) opn=w.oGame;
                }
            }
        } else {
            if(number-gQnty(w,value,g)>=2*(nUsers-1)) opn=w.oGame;
        }
        if(opn==w.oGame) cout<<"Computer Number"<<w.oGame<<" challenge"<<endl;
        else cout<<"Computer Number"<<w.oGame<<" does not challenge"<<endl;
    }
}

void cBidding(int opn,User &w,char &value,int &number,int &v,bool g) {
    //bidding
    if(opn==-1) {
        char fTem;
        if(g) {
            vector<char> nExist=gNEx(w.dice);
            //truth 3/5
            if(rand()%5>=2||(nExist.size()==1&&nExist[0]=='1')) {  
                if(rand()%3<2&&value==gFreq(w.dice))  { //get the most frequent value of of AI's dice
                    fTem=value;
                } else { //randomly get a dice from existed dice
                    vector<char> ext=gEx(w.dice);

                    do {
                        fTem=ext[rand()%ext.size()];
                    } while(fTem=='1');
                }

                if(fTem<=value) number++;
                value=fTem;


            } else { //lie 2/5
                //The value of dice that the computer doesn't have
                char fTem;
                do {
                    fTem=nExist[rand()%nExist.size()];
                } while(fTem=='1');
                if(fTem<=value) number++;
                value=fTem;
            }
        } else {
            value=gFreq(w.dice);
            if(fTem<=value) number++;
        }
        cout<<"Computer Number"<<w.oGame<<" bidding "<<number<<"  "<<value<<"s";
        if(g) cout<<" "<<endl;
        else cout<<" only"<<endl;
        v++;
    }
}

//The quantity of one value of dice of one user
int gQnty(User w,char value,bool g) { 
    int number=0;
    int ons=0;
    for(int i=0;i<5;i++) {
        if(w.dice[i]==value) number++;
        if(g&&value!='1'&&w.dice[i]=='1') ons++;
        //When 1 is not wild
    }
    return number+ons;
}

//The value of dice that doesn't ext in computer
vector<char> gNEx(char *dice) {
    vector<char> nExist;//not ext value of dice
    //initialize 6 elements from 1 to 6
    for(int i=1;i<=6;i++) {
        nExist.push_back(i+48);
    }
    //when the value of the dice comes up, set that value in the vector to 0
    for(int i=0;i<5;i++) {
        nExist[static_cast<int>(dice[i]-48)-1]='0';
    }
    //Sort the vector form high to low
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<6;j++) {
            if(nExist[i]<nExist[j]) {
                char temp=nExist[i];
                nExist[i]=nExist[j];
                nExist[j]=temp;
            }
        }
    }
    //File the existing number
    for(int i=5;i>=0;i--) {
        if(nExist[i]=='0') nExist.pop_back();
    }
    return nExist;//return the vector
}

//The value of dice that ext in computer
vector<char> gEx(char *dice) {
    bool isd;
    vector<char> ext;
    for(int i=0;i<5;i++) {
        isd=false;
        //use for loop to get the existing dice
        for(int j=0;j<ext.size();j++) {
            if(ext[j]==dice[i]) isd=true;
        }
        if(!isd) ext.push_back(dice[i]);
    }
    return ext;
}

//The most frequent value of dice in the dice
char gFreq(char *dice) {
    int *temp=new int[5];
    int count=1;//Count for the dice
    int high;//Highest number
    int index;//index
    //If dice: 2 2 3 4 2, then temp: 3 3 1 1 3
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(dice[i]==dice[j]) count++;
        }
        temp[i]=count;
        count=1;
    }
    high=temp[0];//initial the highest number
    index=0;//initial the index
    //File the highest and its index
    for(int i=0;i<5;i++) {
        if(temp[i]>high) {
            high=temp[i];
            index=i;
        }
    }
    delete []temp;//delete allocate memory
    return dice[index];
}

//Output the result
void rstl(int number,char value,int nUsers,User *users,int opn,bool g) {
    int total=0;
    //Count the value of all users
    for(int i=0;i<nUsers;i++) {
        total+=gQnty(users[i],value,g);
    }
    cout<<endl<<"There are "<<total<<" "<<value<<"s"<<endl;
    if(total>=number) {
        if(opn==0) cout<<"Your challenge failed"<<endl;
        else cout<<"Computer Number"<<opn<<"'s challenge failed"<<endl;
    } else {
        if(opn==0) cout<<"Your challenge succeed"<<endl;
        else cout<<"Computer Number"<<opn<<"'s challenge succeed"<<endl;
    }
}