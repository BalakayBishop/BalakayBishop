//
//  Project CPP.cpp
//  CSC 252
//
//  Created by Blake Bishop on 12/21/21.
//

#include <iostream>
#include "myUtils.h"
#include "Project.h"

Robot :: Robot( int x, int y, char c, bool b )
{
    if( x >= 0 && x < 10 )
    {
        xLocation = x;
    }
    if( y >= 0 && y < 10 )
    {
        yLocation = y;
    }
    load = c;
    cargoBed = b;
}

Robot :: ~Robot()
{
    
}

int Robot :: getXLocation() const
{
    return xLocation;
}
int Robot :: getYLocation() const
{
    return yLocation;
}
char Robot :: getLoad() const
{
    return load;
}
bool Robot :: getCargoBed() const
{
    return cargoBed;
}

void Robot :: setXLocation ( const int& x)
{
    if( x >= 0 && x < 10 )
    {
        xLocation = x;
    }
}
void Robot :: setYLocation ( const int& y)
{
    if( y >= 0 && y < 10 )
    {
        yLocation = y;
    }
}
void Robot :: setLoad ( const char& l)
{
    load = l;
}
void Robot :: setCargoBed ( bool b )
{
    cargoBed = b; 
}

bool Robot :: moveTo( int lX, int lY)
{
    if ( !( lX >= 0 && lX <= 10) )
        return false;
    if ( !( lY >= 0 && lY <= 10) )
        return false;
    
    int diffInX = xLocation - lX;
    int diffInY = yLocation - lY;
    
    int xStep = abs(diffInX);
    int yStep = abs(diffInY);
    
    if ( diffInX > 0)

        for ( int i = 0; i < xStep; i++)
        {
            xLocation--;
        }
    else
        for ( int i = 0; i < xStep; i++)
        {
            xLocation++;
        }
    
    if ( diffInY > 0)
        for ( int i = 0; i < yStep; i++)
        {
            yLocation--;
        }
    else
        for ( int i = 0; i < yStep; i++)
        {
            yLocation++;
        }
    return true;
}

bool Robot :: pickUp( int lX, int lY)
{
    if ( !( lX >= 0 && lX <= 10) )
        return false;
    if ( !( lY >= 0 && lY <= 10) )
        return false;
    if ( board[lX][lY] != '.' )
    {
        if ( cargoBed == false && load == '.' )
        {
            moveTo(lX, lY);
            load = board[lX][lY];
            cargoBed = true;
            board[lX][lY] = '.';
            
            return true;
        }
        else
        {
            cout << "The robot already has a load";
            return false;
        }
    }
    cout << "Out of range board location" << endl;
    return false;
}

bool Robot :: dropOff( int lX, int lY)
{
    if ( !( lX >= 0 && lX <= 10) )
        return false;
    if ( !( lY >= 0 && lY <= 10) )
        return false;
    if ( board[lX][lY] == '.' )
    {
        if ( cargoBed != false && load != '.' )
        {
            moveTo(lX, lY);
            board[lX][lY] = load;
            cargoBed = false;
            load = '.';
            
            return true;
        }
        else
        {
            cout << "The robot already has no load to drop";
            return false;
        }
    }
    cout << "Out of range board location" << endl;
    return false;
}

