#include <iostream>

using namespace std;

int main()
{
  float deg,sum, max , min , avg ;
 min = 50000;
  int n;
  cout << "Enter number of students\n";
  cin>> n;
  for (int i=1 ; i<=n ; i++)
  {
      cout << "Enter degree of student "<<i<<endl ;
      cin>>deg;
      if (deg < 1 || deg > 100 )
      {

        cout << "Wrong degree"<<endl;
        i-- ;
        continue;
      }
      sum += deg ;
      if (deg > max )
      {
        max = deg ;
      }
      if (deg < min )
      {
        min = deg ;
      }
  }
  avg = sum / n ;
  cout << "Average = "<<avg<<endl;
  cout << "maximum degree is "<< max <<endl << "Minimum degree is "<<min<< endl ;
    return 0;
}
