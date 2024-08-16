#include <iostream>

using namespace std;

int main()
{
    float n=0 , sum = 0 ;
    cout <<"Enter the value"<<endl ;
    cin>>n;
    for (int i=1 ; i <= n ; i++ )
        sum += 1.0/i ;
    cout << "sum : " << sum<<endl ;
    return 0;
}
