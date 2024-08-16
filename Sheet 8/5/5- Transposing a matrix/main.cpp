#include <iostream>

using namespace std;

int main()
{
    const int rows_A = 2 ;
    const int cols_A = 4 ;
    int a[rows_A][cols_A] = {{1,2,3,4},{4,5,6,7} } ;
    int a_transpose[cols_A][rows_A] ;
    for (int j =0 ; j<cols_A ; j++ )
    {
        for(int i=0 ; i<rows_A ; i++ )
        {
            a_transpose[j][i] = a[i][j] ;
        }
    }
    for(int i=0 ; i<cols_A;i++)
    {
        for(int j=0 ; j < rows_A ; j++)
        {
            cout << a_transpose[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0;
}
