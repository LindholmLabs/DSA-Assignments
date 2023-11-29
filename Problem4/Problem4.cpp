// Problem 1: Bucket Sort
// Description: Sort a vector using a modified version of bucket sort.
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//

#include <iostream>
#include <cmath>

using namespace std;

// Temp
// Från labbanvisningarna
// T(n) = T(n-1)+T([n/2])+n
// T(1) = 1
// Recursive function to calculate T(n)
int T(int n) {
    int result = T(n - 1) + T(ceil(n / 2.0)) + n;

    return result;
}

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;
    cout << "T(" << n << ") = " << T(n) << endl;
    return 0;
}
