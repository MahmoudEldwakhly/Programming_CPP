#include <iostream>

using namespace std;

int main()
{
   int x , fact =1  ;
   cout <<"Enter any number"<<endl;
   cin >>x;
   for (int i =1 ; i<=x ; i++ )
   {
   fact *= i ;
   }
   cout <<"Factorial of "<<  x << " = "<<fact<<endl;
    return 0;
}
