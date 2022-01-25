//
//  Project.h
//  CSC 252
//
//  Created by Blake Bishop on 12/21/21.
//

#pragma once

#include <iostream>
#include "myUtils.h"
using namespace std;

char board[10][10];

void print2D( char grid[10][10], int sizeArray )
{
    for ( int i = 0; i < 10; i++ )
    {
        for ( int j = 0; j < 10; j++ )
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

class Robot
{
public:
    
    Robot( int x, int y, char c, bool b ); 
    ~Robot();
    
    int getXLocation() const;
    int getYLocation() const;
    char getLoad() const;
    bool getCargoBed() const;
    
    void setXLocation ( const int& x);
    void setYLocation ( const int& y);
    void setLoad ( const char& l);
    void setCargoBed ( bool b );
    
    bool moveTo( int lX, int lY);
    bool pickUp( int lX, int lY);
    bool dropOff( int lX, int lY); 
    
private:
    int xLocation;
    int yLocation;
    char load;
    bool cargoBed;
    
    friend ostream& operator<< ( ostream& out, const Robot& r );
};
