#include <iostream>

using namespace std;

int main()
{
    int maxpower = 15000;
   float x,y ;
   int z;
   cout <<"choose number : angle in 1- degree or 2- radian"<<endl;
   cin>>z;
   if (z==1)
   {

   cout <<"Enter angle in degrees "<<endl;
   cin>>y;
   x=(y/180.0)*3.143;
   }
   else if (z==2)
   {
       cout <<"Enter angle in radian"<<endl;
       cin>>y;
       x=y;
   }

   float sum = x;
   float currentterm;
   float previousterm=x;
   int sign = -1;
  for(int i = 3 ; i<=maxpower; i+=2)
   {
       currentterm=(previousterm*x*x)/(i*(i-1));
       sum+=sign*currentterm;
       sign=sign*-1;
       previousterm=currentterm;
   }
    cout<<sum<<endl;


    return 0;
}
