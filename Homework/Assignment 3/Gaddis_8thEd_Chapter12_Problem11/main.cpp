/* 
 * File:   main.cpp
 * Author: Jose Roman
 * Created on October 2, 2015
 * Purpose: Gaddis Chapter 12 Problem 11
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

struct Season
{
    float sl[4];
};
struct Store
{
    //Seasons;
    string div[4]={"east", "west", "north", "south"};
    float quarter[4][4];
    float totQua[4];
};
void print(Store, int);
int main(int argc, char** argv) 
{
    Store run;
    float temp=0.0;
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            cout << "Enter the sales for quarter "<<j+1<<" in the "<<run.div[i]<< " division"<< endl;
            do
            {
                cin >> run.quarter[i][j];
                if(run.quarter[i][j]<0)
                    cout <<"INVALID INPUT"<< endl;
            }while(run.quarter[i][j]<0);
            
            temp+=run.quarter[i][j];
        }
        run.totQua[i]=temp;
        print(run, i);
        temp=0.0;
    }
    
    
    return 0;
}
void print(Store run, int d)
{
    ofstream ofile;
    string temp=run.div[d];
    ofile.open(temp.c_str());
    ofile << fixed << showpoint << setprecision(2);
    ofile<<"total $"<<run.totQua[d];
    ofile<<" quarters "<< endl;
    for(int i=0;i<4;i++)
    {
        ofile<<" $ "<<run.quarter[d][i]<< endl;
        //cout<<run.quarter[d][i]<< endl;
    }
}