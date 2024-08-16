#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char c [20] ;
  gets(c) ;
  for (int i = 0 ; i<strlen(c) ; i ++ )
    cout << c [strlen(c)-1-i] ;
  cout << endl ;

    return 0;
}
