#include <iostream>
#include<cstring>

using namespace std;

int main()
{
  const int rows = 5 ; // No of names
  const int cols = 26 ; // 25 character of each name + null character
  char names [rows][cols] ;
// get names from user
for (int i=0 ; i<rows ; i++)
{
    cout << "Enter name of student no. " <<i+1<<" : " << endl ;
    gets (names[i]) ;
}
// get sure all characters small letters
for (int i=0 ; i<rows ; i++ )
{
    for (int j=0 ; j<cols ; j++ )
    {
        if (names[i][j] >= 'A' && names[i][j] <= 'Z' )
        {
            names[i][j] = names[i][j] + ('a' - 'A') ;
        }
    }
}

// Sorting
char temp [cols] ;
for (int i = 0 ; i<rows-1 ; i++)    // same as sorting numbers but numbers by n-1
{
    for (int j =0 ; j< rows-1 ; j++)
        {
            if (strcmp(names[j] , names [j+1]) == 1 )
            {
                strcpy (temp , names [j]) ;
                strcpy ( names [j] , names [j+1]) ;
                strcpy ( names [j+1] , temp ) ;
            }
        }
}

cout <<endl ;
cout <<"Sorted names : " << endl ;

//Printing sorted Names
for (int i = 0 ; i<rows ; i++ )
{
    cout << names[i] << endl ;
}



    return 0;
}
