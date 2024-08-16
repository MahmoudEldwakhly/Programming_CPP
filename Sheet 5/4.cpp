#include <iostream>
#include <math.h>
using namespace std;
void printarray (int a [] ,int size )
{
    cout << "printing .... " << endl ;
    for (int i = 0 ; i < size ; i ++ )
    {
        cout << a [i] << " " ;
    }
    cout << endl ;
}
float arrayaverage (int a [] , int size )
{
int sum = 0 ;
for (int i=0 ; i< size ; i ++ )
{
    sum+=a[i] ;
}
return sum *1.0 / size  ;
}
int maxarray (int a [] , int size )
{
int max = a [0] ;
for (int i = 0 ; i < size ; i++)
{
    if (a [i] > max )
        max = a [i] ;
}
return max ;
}

int minarray (int a [] , int size )
{
int min = a [0] ;
for (int i = 0 ; i < size ; i++)
{
    if (a [i] < min )
        min = a [i] ;
}
return min;
}
void sortarray(int a[] , int size)
{
    for (int i = 0 ; i < size-1 ; i ++  )   // Iterations
    {
        for (int j = 0 ; j<size-1 ; j ++ ) // comparison in each iteration , it can be also j<size -1 - i .
        {
            if (a [j] > a [j+1] )
            {
                int temp = a[j] ; a[j] = a [j+1] ; a[j+1] = temp ;

            }
        }


    }
}
int medianarray ( int a [] , int size )
{
    sortarray ( a , size ) ;
    return a [size / 2 ] ;
}

int main ()
{
const int size = 7 ;
int x[size] = {6,5,3,1,2,4 ,7} ;

cout << "Array average = "<< arrayaverage ( x  , size )<<endl ;
cout << "minimum = " << minarray(x , size) << endl ;
cout << "maximum = " << maxarray(x , size) << endl ;
printarray ( x , size ) ;
sortarray ( x , size ) ;
printarray (x , size ) ;
cout << "Median = " << medianarray (x , size ) << endl ;
    return 0;
}
