#include <iostream>

using namespace std;
vowels (char s[] , int index )
{
    if ( s [index] == '\0'  ) return 0 ;
    int var = 0 ;
    if ( s[index]=='a'||s[index]=='A'||
        s[index]=='E'||s[index]=='e'||
        s[index]=='U'||s[index]=='u'||
        s[index]=='o'||s[index]=='O'||
        s[index]=='i'||s[index]=='I' )
            var = 1 ;
    return var + vowels (s,index+1) ;
}

int main()
{
    char s [100] ;
    cout << "Enter any sentence " << endl;
    gets(s) ;
    cout << "No of vowels = " << vowels ( s , 0 ) << endl ;
    return 0;
}
