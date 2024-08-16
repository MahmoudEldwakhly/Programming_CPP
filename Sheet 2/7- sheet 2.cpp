#include <iostream>

using namespace std;
int main ()
{
    float x , y , z
    cout <<"Enter two numbers "<<endl;
        cin >> x,y
    int choice;
    cout << "Please choose number of operation you want from the following "<<endl;
    cout << "1- Addition , 2 - Subtraction , 3- Multiplication , 4- Division , 5- Average , 6- Maximum , 7- minimum "<<endl;
    cin>>choice;
    switch (choice
            {
case 1 :
    z=x+y;
    break;
case 2:
    z=x-y;
    break;
case 3 :
    z=x*y;
    break;
case 4 :
    z=x/y;
    break;
case 5 :
    z=(x+y)/2;
    break;
case 6 :
    z= (x>y)? x : y ;
    break;
    case 7 :
    z=(x>y) ? y : x ;
    break;
    default :
        cout << "Please choose from the these numbers only "<<endl;
}
cout <<"The result equals " << z << endl ;
}
