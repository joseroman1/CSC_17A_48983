/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 8, 2015
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
struct stdnt{  //Student
    string sName;//Name of the student
    string sID;//ID of the student
    int *sScore;//pointer to an array of scores
    float average;//average of sScore
    char cGrade;//the final cGrade
};

//Global Constants

//Function Prototypes
stdnt getInfo(int);
void pntInfo(stdnt);

//Execution begins here
int main(int argc, char** argv) {
    int testNum,//how many test
        sdtNum;//How many students
    //prompt user for the number of test
    do {
        cout<<"Input the number of test for the course?";
        cin>>testNum;
        if(testNum<1)
            cout<<"Wrong input"<<endl;
    } while(testNum<1);
    //prompt user for the number of student
    do {
        cout<<"How many students?";
        cin>>sdtNum;
        if(sdtNum<1)
            cout<<"Wrong input"<<endl;
    } while(sdtNum<1);
    
    //dynamic allocate memory for all student
    stdnt*stud=new stdnt[sdtNum];
    
    //prompt user input data
    for(int i=0;i<sdtNum;i++) {
        cout<<endl<<"Student "<<(i+1)<<": "<<endl;
        stud[i]=getInfo(testNum);
    }
    
    //output the result
    for(int i=0;i<sdtNum;i++) {
        cout<<"Student "<<(i+1)<<": ";
        pntInfo(stud[i]);
    }
    
    //deallocate memory
    delete [] stud;
    stud=0;
    
    //Exit stage right
    return 0;
}

stdnt  getInfo(int testNum) {
    stdnt stu;
    stu.sScore=new int[testNum];
    stu.average=0;
    bool valid;
    //get the Name
    cout<<"Student Name"<<": ";
    cin.ignore();
    getline(cin,stu.sName);

    //input the ID
    do {
        valid=true;
        cout<<"Student ID: ";
        cin>>stu.sID;
        //check the id number
        for(int j=0;j<stu.sID.length();j++) {
            if(stu.sID.at(j)<48||stu.sID.at(j)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Wrong input"<<endl;
    }while(!valid);

    //ask for input for all the test   
 for(int j=0;j<testNum;j++) {
        do {
            cout<<"Test #"<<(j+1)<<": ";
            cin>>stu.sScore[j];
            if(stu.sScore[j]<0||stu.sScore[j]>100)
                cout<<"Wrong input"<<endl;
        } while(stu.sScore[j]<0||stu.sScore[j]>100);
        stu.average+=stu.sScore[j];
    }
    //calculate the average of the student test score
    stu.average=stu.average/static_cast<float>(testNum);
    //Grade
    if(stu.average>=91) {
        stu.cGrade='A';
    } else if(stu.average>=81) {
        stu.cGrade='B';
    } else if(stu.average>=71) {
        stu.cGrade='C';
    } else if(stu.average>=61) {
        stu.cGrade='D';
    } else {
        stu.cGrade='F';
    }
    //deallocate memory
    delete [] stu.sScore;
    //return the structure
    return stu;
}

void pntInfo(stdnt s) {
    cout<<"Name: "<<s.sName<<"  ID: "<<s.sID<<endl;
    cout<<"  The average test Score: "<<s.average<<"  Class Grade: "<<s.cGrade<<endl;
}