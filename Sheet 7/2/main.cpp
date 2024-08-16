#include <iostream>

using namespace std;
int GCD (int a , int b )
{
    if (b==0) return a ;  // stopping condition
    else
    return GCD(b,a%b ) ;// Recursive statement
}

int main()
{
   int a,b ; cin >> a>>b;
   cout << GCD(a,b) << endl ;
    return 0;
}
