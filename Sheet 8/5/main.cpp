#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
const int rows_a = 2 ;
const int cols_a = 4 ;
const int rows_b = cols_a ;
const int cols_b = 2 ;
const int rows_c = rows_a ;
const int cols_c = cols_b ;

void mulm(int a[rows_a][cols_a] , int b[rows_b][cols_b] , int c[rows_c] [cols_c])
{
    for (int i = 0 ; i<rows_a ; i++)
    {
        for (int j=0 ; j < cols_b ; j++)
        {
            int sum = 0 ;
            for (int x = 0 ; x < cols_a ; x++ )
            {
                sum+= a[i][x] * b[x][j] ;
            }
        c[i][j] = sum ;

         }
    }
}

int main()
{
   int a[rows_a][cols_a] = { {1,2,3,4} , {4,5,6,7} } ;
   int b[rows_b][cols_b] = {{1,2} , {4,5} , {1,2} , {4,5} }  ;
   int c[rows_c][cols_c] ;
   mulm(a,b,c) ;
   for (int i = 0 ; i <rows_c ; i++)
   {
       for (int j=0 ; j <cols_c ; j++)
       {
           cout << setw(4) << left << c[i][j] ;
       }
       cout << endl ;
   }




    return 0;
}
