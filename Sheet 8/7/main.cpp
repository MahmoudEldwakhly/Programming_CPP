#include <iostream>

using namespace std;
const int N = 3 ;

int countNonZero(int A[N][N] ) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != 0) {
                count++;
            }
        }
    }

    return count;
}
int multdiagonal (int A[N][N])
{
    int product = 1 ;
    for (int i = 0; i < N; i++)
        {
        product *= A[i][i];

        }
    return product ;
}

int main()
{
    int A [N][N] ;
    cout << "Enter the square matrix elements of size " << N << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    cout << "No of non zero values in this matrix equals " << countNonZero(A) << endl ;

    cout << "Result of multiplication of diagonal of this matrix equals "<<multdiagonal(A) << endl ;




    return 0;
}
