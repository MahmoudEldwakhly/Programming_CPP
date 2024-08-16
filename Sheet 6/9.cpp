//Mahmoud Elsayd Eldwakhly

//21P0017

// LAP ASSIGNMENT 6


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// 1-

void mystrcopy (char z [] , char s [])
{
    for ( int i = 0 ; i<strlen(s)+1 ; i ++ )
    {
        z[i] = s [i] ;
    }

}

// 2-

int mystrlen(char s [])
{
    int i = 0 ;
    while (s[i] != '\0')
        i++ ;
        return i ;
}

// 3-

int mystrcmp (char s1[] , char s2 [] )
{
    int z = (strlen(s1)> strlen(s2)) ? strlen(s1) : strlen(s2) ;
    for (int i = 0 ; i < z ; i ++ )
{
    if (s1[i] < s2 [i] ) return -1 ;
    else if (s1[i] > s2 [i] ) return 1 ;
}
return 0 ;
}

// 4-

int myatoi (char s [])
{
    int result =0 ;


    for (int i = 0 ; i < strlen (s) ; i++)
    {
        result = result * 10 + (s[i]-'0') ;
    }
    return result ;
}


// 5-

float myatof (char m [])
{
    int dotindex = -1 ;
    for ( int i = 0 ; i < strlen(m) ; i ++ )
    {
        if ( m[i]== '.' )
        {
            dotindex = i ;
            break ;
        }
    }
    if (dotindex == -1 )
        return atoi(m) ;
    float integerpart = 0 ;
    for (int i = 0 ; i<dotindex ; i ++ )
    {
        integerpart = integerpart * 10 + (m[i] - '0') ;
    }
    float floatpart = 0 ;
    for (int i = dotindex + 1 ; i<strlen(m) ; i ++ )
    {
        floatpart += (m[i]-'0')* pow(10 , dotindex -i) ;
    }
    return integerpart + floatpart ;
}




int main()
{
    char z [50]  ;
    char m [20] = {'m','a','h','m','o','u','d'} ;
    mystrcopy (z,m) ;
    cout << z << endl ;
    cout << mystrlen(z) << endl ;
    cout << mystrcmp ("abcd" , "abcd") << endl ;
    cout << mystrcmp ("abce" , "abcd") << endl ;
    cout << mystrcmp ("abcd" , "abce") << endl ;
    cout << myatoi ( "12345") << endl ;
    cout << myatof ("123.45") << endl ;


    return 0;
}
