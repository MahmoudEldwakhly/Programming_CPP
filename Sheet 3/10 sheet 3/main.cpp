#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    int y = 1;
    float fact = 1;
    for (int x=1 ; x <= 5 ; x++ )
    {
        for (int y =1 ; y<= x ; y++)
    {
        fact *= y;
    }
        cout << "Factorial of "<< x << "= "<<fact<<endl;
    }
    return 0;
}
