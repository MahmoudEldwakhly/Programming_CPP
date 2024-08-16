#include <iostream>

using namespace std;

int main()
{
   float A = 52;
   float B = 85;
   float Population_growth_A = 0.06;
   float Population_growth_B = 0.04;
   int year = 2023;
   int year_count = 0 ;
   while (A<=B)
   {
    A+=A*Population_growth_A ;
    B+=B*Population_growth_B ;
    year_count++;
    cout <<"Years of A = " << A << "\t"<<"Years of B = "<<B <<"\t "<<"year = " <<year_count <<endl;
   }
  cout << "No of years needed = "<<year_count<<endl;
    return 0;
}
