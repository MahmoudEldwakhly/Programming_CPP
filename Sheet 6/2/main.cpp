#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   char c [20] ;
   gets(c) ;
   for (int i = 0 ; c[i] != '\0' ; i ++ )
   {
       if (c[i]>= 'a' && c[i]<='z' )
        c[i] -= ('a'-'A') ;
   }
   cout << c << endl ;
    return 0;
}
