#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char a [100] ; char b [100] ;
  cout << "Enter first sentence " << endl ;
  gets(a) ; cout << "Enter second sentence" << endl ;
  gets(b) ;
  cout << strcat(a , b) << endl ;



    return 0;
}
