#include <iostream>

using namespace std;

int main()
{
    int x , y ;
    float fact = 1;
    for (int x=1 ; x<=15 ; x++)
    {
        for (int y = 1 ; y<=x ; y++)
        {
            fact*=y;
        }

        cout<<"factorial of "<<x<<"= " <<fact<<endl;
    }
    return 0;
}
