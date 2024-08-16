#include <iostream>

using namespace std;

int main()
{
   int i , sum =0 ;
   for (int i=1 ; i<=100 ; i++ )
   {

    if ( (i%2)==0 && (i%3)==0 )
    sum += i ;
   }
   cout << "sum = " << sum<<endl ;
    return 0;
}
