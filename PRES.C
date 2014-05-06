///////////////////////////
// Program Name: PRES.CPP
///////////////////////////

// Program description:
// This program demonstrates how to use an object as one of 
// the data members of a class.

///////////////////
// #include (C++)
///////////////////
#include <iostream.h>

///////////////////
// #include C
///////////////////
#include <string.h>

//////////////////////////
// Declare the Date class
//////////////////////////
class Date
{
public:
    Date ( int month,    // The constructor function.
           int day,
           int year );
    void DisplayIt();    // Function that displays the date.
    void ChangeDate(int, // Change date.
                    int,
                    int );
    ~Date();             // The destructor function.

     int year;           //<---NOTE: year is public
private:
    int month, day;
};


//////////////////////////////
// Declare the President class
//////////////////////////////
class President
{
public:
      President(char *First_Name,  // The constructor   
                char *Last_Name,   // function.
                int   mn,
                int   dy,
                int   yr );
               
     ~President();    // The destructor function.
      
      Date Birthday; //<--- An object of the Date class!!!

private:
      char FirstName[20];
      char LastName [20];
};


/////////////////////////////////////////////////////
// Function Name: President()
// (The constructor function of the President class)
/////////////////////////////////////////////////////
President::President(char *First_Name,
                     char *Last_Name,
                     int   mn,
                     int   dy,
                     int   yr ):Birthday(mn, 
                                         dy,
                                         yr)
{
cout << "\n Guess what? I'M in the President constructor function";

strcpy(FirstName, First_Name );
strcpy(LastName,  Last_Name  );
}

/////////////////////////////////////////////////////
// Function Name: ~President()
// (The destructor function of the President class)
/////////////////////////////////////////////////////
President::~President()
{
cout << 
  "\n Guess what? I'M in the President destructor function";
}

////////////////////////////////////////////
// Function Name: Date()
// (Constructor function of the Date class)
////////////////////////////////////////////
Date::Date(int mn, int dy, int yr)
{
month = mn;
day   = dy;
year  = yr;
cout << "\n Hi! I'm in constructor of the Date class";
}


///////////////////////////////
// Function Name: DisplayIt()
//////////////////////////////
void Date::DisplayIt()
{
static char *MonthName[] =
         { "Zero", 
           "January", "February", "March",
           "April",   "May",      "June", 
           "July",    "August",   "September", 
           "October", "November", "December" };

cout << "\n Month: " << MonthName[month]
     << "   Day:   " << day 
     << "   Year:  " << year << endl;
}

////////////////////////////////////
// Function Name: ~Date()
// (destructor of the Date class)
///////////////////////////////////
Date::~Date()
{
cout << "\n Good-Bye (from the ~Date() destructor)" << endl;
}

/////////////////////////////////
// Function Name: ChangeDate()
/////////////////////////////////
void Date::ChangeDate ( int i, int j, int k )
{
month = i;
day   = j;
year  = k;
}

/////////////////////////
// Function Name: main()
/////////////////////////
void main( void )
{
int year; // Not a member of any class. Just a local 
          // variable to main().

President Washington ("George", "Washington",
                       2, 21, 1732 );

President Lincoln     ("Abraham", "Lincoln",
                       2, 16, 1809 );

cout << "\n Will now execute: Washington.Birthday.DisplayIt()";
Washington.Birthday.DisplayIt  ();

year = Lincoln.Birthday.year;
cout << "\n Lincoln was born in " << year;

cout << "\n Will now execute:   Washington.Birthday.ChangeDate()";
Washington.Birthday.ChangeDate ( 2, 22, 1732);
cout << "\n Finished executing: Washington.Birthday.ChangeDate()";

cout << "\n Will now execute: Washington.Birthday.DisplayIt()";
Washington.Birthday.DisplayIt  (); 
}
