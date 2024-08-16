#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char c [20] ;
  char v [6]= "aeiou" ;
  int counters [6] = {0} ;
  gets(c) ;
  for (int i = 0 ; i<strlen(c) ; i ++ )
    {
        if (c[i] >= 'A' && c[i] <= 'Z' )
        c[i] += ( 'a' - 'A' ) ;
    }
    for (int i = 0 ; i<strlen(c) ; i++ )
    {
        char currentchar = c[i] ;
        for (int j = 0 ; j < strlen(v) ; j++ )
        {
            if (v[j] == currentchar )
                counters [j] ++ ;
        }
    }
    for (int i = 0 ; i<strlen(v) ; i++ )
    {
        cout << v[i] << " Repeated " << counters [i] << " times\n"  ;
    }



    return 0;
}
