#include <iostream>

using namespace std;

int main()
{
    float x = 1;
    float y = 1;
    float fact = 1;
    for (int x=1 ; x <= 15 ; x++ )
    {
        for (float y =1 ; y<= x ; y++)
    {
        fact *= y;
    }
        cout << "Factorial of "<< x << "= "<<fact<<endl;
    }
    return 0;
}
