#include <iostream>

using namespace std;

int main()
{
    int choice;
    float x,y;
    cout << "Choose number of the shape to compute it is area and perimeter \n";
    cout << "1- Rectangle , 2- square , 3- Circle  ";
    cin >> choice;
    switch (choice)
    {
    case 1 :
        cout << "Insert length and width of the rectangle"<<endl;
        cin>>x>>y;
        cout <<"Perimeter : "<< 2*(x+y) <<endl;
        cout <<"Area : " << x*y <<endl ;
        break ;
         case 2 :
        cout << "Insert side length of the square"<<endl;
        cin>>x;
        cout <<"Perimeter : "<< 4*x <<endl;
        cout <<"Area : " << x*x <<endl ;
        break ;
         case 3 :
        cout << "Insert Radius of the circle "<<endl;
        cin>>x;
        cout <<"Perimeter : "<< 2*(22.0/7)*x <<endl;
        cout <<"Area : " << (22/7)*x*x <<endl ;
        break ;

    }
    return 0;
}
