/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 8, 015
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct weather {
    int rainfall;// rainfall
    int hgTemp;//high temperature
    int lwTemp;//low temperature
    float agTemp;//average temperature
};

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    const int SIZE=12;
    weather mnth[SIZE];
    //Ask for input from the user to fill in the weather
    for(int i=0;i<SIZE;i++) {
        cout<<"Month Number"<<(i+1)<<": "<<endl;
        //get the rainfall data
        do {
            //Get the rainfall data
            cout<<"     Total Rainfall(mm): ";
            cin>>mnth[i].rainfall;
            if(mnth[i].rainfall<0)
                cout<<"Wrong  input"<<endl;
        } while(mnth[i].rainfall<0);
        //get the temperature
        do {
            cout<<"     High temperature (F): ";
            cin>>mnth[i].hgTemp;
            if(mnth[i].hgTemp<-100||mnth[i].hgTemp>140)
                cout<<"Wrong input(out of range)"<<endl;
        } while(mnth[i].hgTemp<-100||mnth[i].hgTemp>140);
        //get the low temperature
        do {
            cout<<"     Low temperature(F): ";
            cin>>mnth[i].lwTemp;
            if(mnth[i].lwTemp<-100||mnth[i].lwTemp>140)
                cout<<"**Invalid input(out of range)**"<<endl;
            if(mnth[i].lwTemp>mnth[i].hgTemp)
                cout<<" Low temperature can't be greater than high temperature.. Input again!"<<endl;
        } while(mnth[i].lwTemp<-100||mnth[i].lwTemp>140||mnth[i].lwTemp>mnth[i].hgTemp);
        //calculate the average temperature
        mnth[i].agTemp=0.5f*(mnth[i].hgTemp+mnth[i].lwTemp);
        
    }
    int yearRn=0;// rainfall in a year
    float avgRn=0;//average rainfall each month
    float avgTemp=0;//average temperature of all months
    int hstTemp=mnth[0].hgTemp;//highest temperature
    int lwTemp=mnth[0].lwTemp;//lowest temperature
    int idxMnt=0,ilw=0;//the index of mnth
    for(int i=0;i<SIZE;i++) {
        //sum all total rainfall
        yearRn+=mnth[i].rainfall;
        avgTemp+=mnth[i].agTemp;//average temperature
        if(mnth[i].hgTemp>hstTemp) {
            hstTemp=mnth[i].hgTemp;
            idxMnt=i;
        } else if(mnth[i].lwTemp<lwTemp) {
            lwTemp=mnth[i].lwTemp;
            ilw=i;
        }
    }
    // average temperature and average rainfall
    avgTemp=static_cast<float>(avgTemp)/SIZE;
    avgRn=static_cast<float>(yearRn)/SIZE;
    
    //output the results
    cout<<setprecision(2)<<fixed;
    cout<<"Average monthly rainfall(mm) is "<<avgRn<<endl;
    cout<<"Total rainfall(mm) for the year is "<<yearRn<<endl;
    cout<<"Highest temperature(F) is "<<hstTemp<<" in "<<"Month "<<"#"<<(idxMnt+1)<<endl;
    cout<<"Lowest temperature(F) is "<<lwTemp<<" in "<<"Month "<<"#"<<(ilw+1)<<endl;
    cout<<"The average of all the monthly average temperatures(F) is "<<avgTemp<<endl;
    //Exit stage right
    return 0;
}