//////////////////////////////////////////////////////
// Program Name: SRO.CPP (Scope Resolution Operator).
//////////////////////////////////////////////////////

// Program Description:
// This program illustrates how to use the scope 
// resolution operator.

//////////////
// #include
//////////////
#include <iostream.h>

/////////////////////
// Global variables 
/////////////////////
int iAccount = 200;

//////////////////////////
// Function Name: main()
//////////////////////////
void main ( void )
{
cout << "\n Results:";
cout << "\n -------";
int iAccount = 100;
cout << "\n I am the local:  iAccount = "
     << iAccount;

cout << "\n I am the global: iAccount = "
     << :: iAccount << endl;
}
