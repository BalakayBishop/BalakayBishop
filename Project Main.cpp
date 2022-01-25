//
//  Project Main.cpp
//  CSC 252
//
//  Created by Blake Bishop on 12/20/21.
//

#include <iostream>
#include "myUtils.h"
#include "Project.h"

using namespace std;

ostream& operator<< ( ostream& out, const Robot& r )
{
    out << "(" << r.xLocation << " , " << r.yLocation << "):" << r.load;
    return out;
}

void clear( char board[][10], int sizeArray )
{
    Robot* r;
    for ( int i = 0; i < 10; i++ )
    {
        for ( int j = 0; j < 10; j++ )
        {
            if ( board[i][j] != '.')
            {
                r = new Robot (i, j, false, '.');
                r->pickUp(i, j);
                delete r;
            }
        }
    }
}

int main()
{
    for ( int r = 0; r < 10; r++ )
    {
        for ( int c = 0; c < 10; c++ )
        {
            board[r][c] = '.';
        }
    }
    
    board[3][8] = 'B';
    board[2][6] = 'C';
    
    print2D(board, 10);
    
    Robot r1( 0, 0, '.', false );
    Robot r2( 0, 0, '.', false );
    
    cout << r1 << endl;
    cout << r2 << endl;
    
    r1.moveTo(9, 2);
    r2.moveTo(3, 4);
    
    r1.pickUp(3, 8);
    r1.dropOff(9, 9);
    cout << r1 << endl;
    
    r2.pickUp(2, 6);
    r2.dropOff(0, 0);
    cout << r2 << endl;
    
    return 0;
}
