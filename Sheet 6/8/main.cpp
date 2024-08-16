#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char x [200] ;
    cout << "Enter paragraph" << endl;
    gets(x) ;
    char required[] = "programming" ;
    int counter = 0 ;

    for (int i = 0 ; i<strlen(x) ; i++ )
    {
        if (x[i] >= 'A' && x[i] <= 'Z' ) x[i] += ('a' - 'A' );
    }
    for (int i = 0 ; i< strlen(x) ; i ++ )
    {
        if (strncmp(&x[i] , required , strlen(required)) == 0 )
            counter ++ ;
    }
    cout << "Programming word repeated " << counter << " times " << endl ;

    return 0;
}
