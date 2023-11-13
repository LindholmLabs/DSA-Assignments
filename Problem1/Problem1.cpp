// Problem 1: Bucket Sort
// Description: Find the target number in the unsorted vector
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran
// Date: 13-11-2023
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function prototype
vector<int> bucketSort(vector<int> unsorted_vector);
string vectorToString(vector<int> vector);

int main()
{
	vector<int> unsorted = { 41, 12, 53, 14, 5, 62, 7, 28, 9 };
	vector<int> sorted = bucketSort(unsorted);

	printf("The unsorted vector: %s\nThe sorted vector: %s",
		vectorToString(unsorted), vectorToString(sorted));

	return 0;
}


/*
 * Function: bucketSort
 * Sort an unsorted vector using bucket sort
 * @param v: the unsorted vector
 * @return: the sorted vector
 */
vector<int> bucketSort(vector<int> v) 
{
	
}


/*
 * Function: vectorToString
 * Print a vector
 * @param vector: the vector to print
 * @return: the string representation of the vector
 */
string vectorToString(vector<int> vector)
{
	string output = "{";
	for (int i = 0; i < vector.size(); i++)
	{
		output += to_string(vector[i]) + ", ";
	}
	output += "}";

	return output;
}
