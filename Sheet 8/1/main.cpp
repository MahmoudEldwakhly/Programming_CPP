#include <iostream>

using namespace std;

int main()
{
  const int rows = 10 ;  // No of students
  const int cols = 26 ;  // No of characters in each name of student
  char names [rows][cols] ;
  for (int i = 0 ; i<rows ; i++)
  {
      cout << "Enter name of student " << i+1 << endl ;
      cin.getline(names[i] , cols ) ;
  }
  for (int i =0 ; i< rows ; i++ )
  {
      cout << i+1 << " : " << names[i] << endl ;
  }

    return 0;
}
