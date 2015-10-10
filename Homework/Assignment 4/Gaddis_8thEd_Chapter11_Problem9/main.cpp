/* 
 * File:   main.cpp
 * Author: YESENIA AGUILAR
 *
 * Created on 9 de octubre de 2015, 11:29 PM
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
struct speakers {
    string sName;
    string phNumber;//Phone Number
    string spesTop;//speakersc topic
    int feeRqd;//Fee equired
};

//Global Constants

//Function Prototypes
speakers *intAry(int);//initial all data of speaker
void pntInfo(speakers *,int n);//Print Info
void iptInfo(speakers &);//input the information of one speaker

//Execution begins here
int main(int argc, char** argv) {
    int spkNum;//the number of speaker
    string choice;//choice of menu
    int spk;//the number of speaker
    //Ask user to input user for the number of speaker
    do {
        cout<<"Input the number of speaker: ";
        cin>>spkNum;
        if(spkNum<10)
            cout<<"At least 10. Please input again!"<<endl;
    }while(spkNum<10);
    //initialize the speaker
    speakers *ary=intAry(spkNum);
    do {
        do {
            //display menu
            cout<<endl<<"***********Speaker Menu***********"<<endl;
            cout<<"1.Input/Change information"<<endl;
            cout<<"2.Display all data"<<endl;
            cout<<"3.Exit the program"<<endl;
            cout<<"Input your choice(1, 2 or 3): ";
            cin>>choice;
            if(choice!="1"&&choice!="2"&&choice!="3")
                cout<<"Wrong input"<<endl;
        }while(choice!="1"&&choice!="2"&&choice!="3");
        
        if(choice=="1") {
            do {
                //ask user for edit which speaker
                cout<<"Input the number of the speaker(1 to "<<spkNum<<"): ";
                cin>>spk;
                if(spk<1||spk>spkNum)
                    cout<<"Wrong input"<<endl;
            }while(spk<1||spk>spkNum);
            //edit
            iptInfo(ary[spk-1]);
        }
        //output all data
        if(choice=="2")
            pntInfo(ary,spkNum);
        if(choice!="3") {
            cout<<"Please press Enter to continue..."<<endl;
            cin.ignore();
            cin.ignore();
        }  
    }while(choice!="3");
    delete [] ary;
    ary=0;
    //Exit stage right
    return 0;
}
//initialize
speakers *intAry(int n) {
    speakers*ary=new speakers[n];
    for(int i=0;i<n;i++) {
        ary[i].feeRqd=0;
        ary[i].sName="";
        ary[i].phNumber="";
        ary[i].spesTop="";
    }
    return ary;
}

//get the information of one speaker
void iptInfo(speakers &sp) {
    bool valid;
    //get the name
    cout<<"Name: ";
    cin.ignore();
    getline(cin,sp.sName);
    //get the telephone Number
    do {
        valid=true;
        cout<<"Please input the phone number: ";
        cin>>sp.phNumber;
        for(int i=0;i<sp.phNumber.length();i++) {
            if(sp.phNumber.at(i)<48||sp.phNumber.at(i)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Wrong input"<<endl;
    }while(!valid);
    //get the speaking topic
    cout<<"Speaking topic: ";
    cin.ignore();
    getline(cin,sp.spesTop);
    //get the feeRqd required
    do {
        cout<<"Fee required: ";
        cin>>sp.feeRqd;
        if(sp.feeRqd<0)
            cout<<"Wrong input"<<endl;
    } while(sp.feeRqd<0);
    
}

//output all data
void pntInfo(speakers *ary,int n) {
    for(int i=0;i<n;i++) {
        if(ary[i].sName!="") {
            cout<<"Speaker Number"<<(i+1)<<endl;
            cout<<"  Name: "<<ary[i].sName<<endl;
            cout<<"  Phone Number: "<<ary[i].phNumber<<endl;
            cout<<"  Speaking topic: "<<ary[i].spesTop<<endl;
            cout<<"  Fee Required: "<<ary[i].feeRqd<<endl;
        } else {
            cout<<"Speaker Number"<<(i+1)<<": ";
            cout<<"Empty file"<<endl;
        }
        cout<<endl;
    }
}