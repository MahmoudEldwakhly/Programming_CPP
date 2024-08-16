#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   char c [50];
   cin.getline (c,50) ;
   cout << c[0] << " " ;
   for (int i = 0 ; i<strlen(c) ; i ++ )
   {
       if (c[i] == ' ' )
       cout << c[i+1] << " " ;
   }
   cout <<endl ;
}
