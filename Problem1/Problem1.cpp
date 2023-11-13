// Problem 1: Bucket Sort
// Description: Find the target number in the unsorted vector
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran
// Date: 13-11-2023
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> unsorted_vector = { 41, 12, 53, 14, 5, 62, 7, 28, 9 };
	int target = 53;
	int result = bucketSort(unsorted_vector, target);
	printf("The target is located at index %i", result);
	return 0;
}


/*
 * Function: bucketSort
 * Find the target number in the unsorted vector
 * @param unsorted_vector: the unsorted vector
 * @param target: the target number
 */
int bucketSort(vector<int> unsorted_vector, int target) 
{
	return 3;
}