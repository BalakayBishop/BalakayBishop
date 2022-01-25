//
//  Project.cpp
//  CSC 242
//
//  Created by Blake Bishop on 11/6/21.
// **Read the spec, follow the spec**

#include <iostream>
#include "myUtils.h"
//Make all of the options into functions
//Variable
//Using dispatcher
//If input is x call in the function of that type

const int MAX_ACCOUNTS = 10;

double acctArray[10] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};

typedef enum
{
    Balance = 2,
    Deposit = 3,
    Withdraw = 4,
    Exit = 5,
    UNASS = 100,
} menuSelection;


void printMenu();

void runMenu(const int& menu);

int balance(const int& userNumber);

int deposit(const int& d);

void withdraw(const int& w);

void exit();

bool signIn( const int& userNumber );


int main()
{
    int acctNumber = -1;
    cout << "Please enter your account number ( 0-9 ): ";
    cin >> acctNumber;
    signIn(acctNumber);
    
    acctNumber = acctArray[acctNumber];
    
    //cout << acctNumber << endl; this was to check the value being passed
    
    runMenu(acctNumber);
    
    return 0;
}

bool signIn( const int& userNumber )
{
    bool acctNumber = false;
    if ( acctNumber >= 0 and acctNumber <= 9)
        acctNumber = true;
    
    return acctNumber;
}



void printMenu()
{
    
    cout << "2. Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Exit" << endl;
    
}

void runMenu(const int& menu)
{
    int pass = menu;
    
    printMenu();
    
    cout << "Please make a menu selection ";
    int selection;
    cin >> selection;
    
    switch (selection)
    {
        case 2:
        {
            balance(pass);
            break;
        }
        case 3:
        {
            deposit(pass);
            break;
        }
        case 4:
        {
            withdraw(pass);
            break;
        }
        case 5:
        {
            exit();
            break;
        }
    }
    
}


int balance(const int& userNumber)
{
    int b = userNumber;
    
    if ( b < 100 )
    {
        cout << "Low balance" << endl;
        runMenu(b);
    }
    
    else if (b > 100)
    {
        cout << "Your balance is: $" << b << endl;
        runMenu(b);
    }
    cout << b << endl;
    return b;
}

int deposit(const int& d)
{
    int newAmount = d;
    cout << "Please enter the amount to deposit: $";
    int depositAmount;
    cin >> depositAmount;
    
    if(depositAmount < 0)
    {
        cout << "Negative values not allowed." << endl;
    }
    else
        newAmount += depositAmount;
    
    runMenu(newAmount);
    
    return newAmount;
}

void withdraw(const int& w)
{
    int newAmount = w;
    cout << "Please enter the amount to withdraw: $";
    int withdrawAmount;
    cin >> withdrawAmount;
    
    if(withdrawAmount < 0)
    {
        cout << "Negative values not allowed, account balance is "
        << acctArray[w] << endl;
    }
    else
        newAmount -= withdrawAmount;
    
    runMenu(newAmount);
}

void exit()
{
    int accountNumber = -1;
    
    cout << "Goodbye!" << endl;
    cout << "Hello, please enter your account number ( 0-9 ): ";
    cin >> accountNumber;
    
    accountNumber = acctArray[accountNumber];
    
    signIn( accountNumber );
    runMenu(accountNumber);
}
