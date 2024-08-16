#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int N, A[MAX_SIZE][MAX_SIZE] ;

    cout << "Enter the size of the square matrix: ";
    cin >> N;

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " " ;
        }
        cout << endl ;
    }

return 0 ; }
