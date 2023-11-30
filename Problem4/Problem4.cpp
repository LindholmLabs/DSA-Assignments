// Problem 1: Bucket Sort
// Description: Sort a vector using a modified version of bucket sort.
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//

#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

// A map to store already calculated results
unordered_map<int, int> storage;

int T(int n) {
    // Check if the result for n is already computed
    if (storage.find(n) != storage.end()) {
        return storage[n];
    }

    // Base case
    if (n == 1) {
        return 1;
    }

    // Calculate T(n-1) and T(ceil(n/2)) if not already done
    int result = T(n - 1) + T(std::ceil(n / 2.0)) + n;

    // Store the result in the map before returning
    storage[n] = result;

    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Compute and print the result
    cout << "T(" << n << ") = " << T(n) << std::endl;

    return 0;
}
