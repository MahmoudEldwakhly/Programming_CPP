#include <iostream>

using namespace std;

int main()
{
    char c;
    cout << "Enter any character" << endl;
    cin>>c;
    int ascii = (int)c;

    cout<<"The ascii code in decimal is : "<< dec<<ascii<<endl;
    cout<<"The ascii code in hexadecimal is : "<< hex<<ascii<<endl;
    cout<<"The ascii code in octadecimal is : "<<oct<<ascii<<endl;
    return 0;
}
