#include <iostream>

using namespace std;
int main ()
{
double comm_rate , goal , salary , salary_per_year , sales_amount;
cout <<"Please enter your goal"<<endl;
cin >> goal ;
cout << "Please enter your monthly salary"<<endl ;
cin>>salary;
salary_per_year = salary*12;
double required = (goal-salary_per_year);
if (required <= 5000*0.8 )
comm_rate= 0.08;
else if (required <= 10000*0.1 )
comm_rate= 0.1;
else
comm_rate= 0.12;
sales_amount = (required /comm_rate);
cout<<"The required sales amount = "<<sales_amount <<endl;



}
