#include <iostream>
#include<iomanip>

using namespace std;
void addm (float a [][3] , float b[][3] , float c [][3])
{
    const int rows = 3 ;
    for (int i=0 ; i<3 ;i++)
    {
        for (int j=0;j<rows;j++)
        {
          c[i][j] = a[i][j] + b[i][j] ;
        }
    }
}

void subm (float a [3][3] , float b[3][3] , float c [3][3])
{

    for (int i=0 ; i<3 ;i++)
    {
        for (int j=0;j<3;j++)
        {
          c[i][j] = a[i][j] - b[i][j] ;
        }
    }
}

int main()
{
   float a [3][3] = {{1,2,3} , {4,5,6} , {6,7,8} } ;
   float b [3][3] = {{6,7,8} , {10,5,11} , {2,5,8} } ;
   float c [3][3] ;
   addm(a,b,c) ;
    for (int i=0 ; i<3 ;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << setw(4) << left << c[i][j] ;
        }
        cout <<endl ;
    }

    subm(a,b,c) ;
    for (int i=0 ; i<3 ;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << setw(4) << left << c[i][j] ;
        }
        cout <<endl ;
    }

    return 0;
}
