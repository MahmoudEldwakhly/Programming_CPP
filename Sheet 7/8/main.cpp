#include <iostream>

using namespace std;
void search (int a[] , int size , int index , int number )
{
    if (a[index] == number ) cout << "It is at index : " << endl << index << endl;
    if (a[index] == size ) return ;
    search ( a , size , index+1 , number ) ;


}

int main()
{
   const int size = 8 ;
   int a [size] = {1,2,3,5,2,4,5,6} ;
   int number ;
   cout << "Enter number to search for in array "  << endl ;
   cin >> number ;
      search ( a ,  size ,  0 , number ) ;

    return 0;
}
