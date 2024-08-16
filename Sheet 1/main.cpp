#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a,b,gr,gd,c;
    float pi = 3.14159;
    cout << "Enter both sides of triangle" << endl;
    cin >> a >> b ;
    cout << "Enter the angle between them in degrees\n";
    cin>> gd ;
    gr = (gd*pi)/180.0;
    c = sqrt(a*a+b*b-2*a*b*cos (gr));
    cout<<"The third side equals : "<<c<<endl;


    return 0;
}
