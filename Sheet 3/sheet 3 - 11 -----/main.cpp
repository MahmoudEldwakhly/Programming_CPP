#include <iostream>

using namespace std;

int main()
{
    for (int i = 1 ; i<=4 ; i++ )
    {
        for (int j =3 ; j>=i;j--)
            cout <<" ";
        for (int k = 1 ; k <= 2*i-1 ; k ++ )
            cout << "*" ;
        cout <<endl;
    }

    for (int i = 4 ; i>=1 ; i-- )
    {
        for (int j =3 ; j>=i;j--)
            cout <<" ";
        for (int k = 1 ; k <= 2*i-1 ; k ++ )

            cout << "*" ;
        cout <<endl;
    }

    return 0;
}

