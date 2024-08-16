#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
   const int n = 2 ;
    int matrix[n][n];
    int sum = 0;



    // Read in the matrix elements
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Compute the sum of diagonal elements
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    // Output the result
    cout << "The sum of diagonal elements is " << sum << endl;

    return 0;
}

