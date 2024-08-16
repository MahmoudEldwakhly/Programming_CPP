#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   const int rows = 100 ; const int cols = 100 ;
   int arr[rows][cols] ;
   srand(time(0)) ;       // TO CHANGE RONDOM NUMBERS GENERATED EACH RUN ( TIME IS ALWAYS CHANGEABLE )
   for (int i = 0 ; i<rows ; i++)
   {
       for (int j = 0 ; j<cols ; j++)
       {
           arr[i][j] = (rand()%1000)+1 ;     // Generate rundom numbers from 1 to 1000
       }
   }
   int counter = 0 ;

   for (int i = 1 ; i<rows -1 ; i++)          //  To ignore first and last ( row and column )
   {
       for (int j = 1 ; j<cols-1 ; j++)
       {
          if (  arr[i][j] < arr[i-1][j-1] &&
                arr[i][j] < arr[i][j-1]   &&
                arr[i][j] < arr[i+1][j-1] &&

                arr[i][j] < arr[i-1][j]   &&
                arr[i][j] < arr[i+1][j]   &&

                arr[i][j] < arr[i-1][j+1] &&
                arr[i][j] < arr[i][j+1]   &&
                arr[i][j] < arr[i+1][j+1]   )

                counter ++ ;

       }
   }

   for (int i = 0 ; i<rows ; i++)
   {
       for (int j = 0 ; j<cols ; j++)
       {
           cout << arr[i][j] << " " ;
       }

   }

   cout << endl ;
   cout << "No of values satisfy conditions " << counter << endl ;





    return 0;
}
