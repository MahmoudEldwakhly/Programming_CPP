#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   char alpha [27] = "abcdefghijklmnopqrstuvwxyz" ;
   char x [200] ; int counters [26] = {0} ;
   cout << "Enter sentence " << endl ;
  cin.getline(x,200);
   for (int i = 0 ; i < strlen(x) ; i++ )
   {
       if (x[i] >= 'A' && x[i] <= 'Z')
        x[i] += 'a' - 'A' ;
   }
   for (int i = 0 ; i< strlen(x) ; i++ )
   {
       for (int j = 0 ; j < strlen(alpha) ; j++ )
       {
           if (x[i]== alpha [j] )
            counters [j] ++ ;
       }
   }
   for (int i = 0 ; i< strlen(alpha) ; i++ )
   cout << alpha [i] << " Repeated " << counters [i] << " times " << endl ;
    return 0;
}
