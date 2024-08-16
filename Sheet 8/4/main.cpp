#include <iostream>
#include <iomanip>
using namespace std ;

const int N = 3;
const int M = 4;

void printMatrix(int matrix[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(4) << left << matrix[i][j] ;
        }
        cout << endl;
    }
}

int main() {

    int matrix[N][M] ;
    cout << "Enter matrix of size " << N << " times " << M << endl ;
     for (int i = 0; i < N; i++)
        {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix [i][j] ;
        }
        }
        printMatrix(matrix) ;



    return 0;
}





