// Problem 1: Bucket Sort
// Description: Find the target number in the unsorted vector
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 13-11-2023
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Function prototypes
vector<int> bucketSort(vector<int> unsortedVector);
string vectorToString(vector<int> vector);
int findMax(vector<int> v);

int main()
{
	vector<int> unsorted = { 41, 12, 12, 53, 14, 5, 62, 7, 12, 28, 9 };
	vector<int> sorted = bucketSort(unsorted);

	cout << "The unsorted vector: " << vectorToString(unsorted) << endl;
	cout << "The sorted vector: " << vectorToString(sorted) << endl;

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
	int max = findMax(v);

	// Create buckets (each bucket is a vector)
	vector<vector<int>> w(max + 1, vector<int>());
	
	// Add values to buckets
	for (int i = 0; i < v.size(); i++)
	{
		w[v[i]].push_back(v[i]);
	}

	// Create sorted vector
	vector<int> sorted(0);

	// Append from buckets in order to sorted vector
	for (int i = 0; i < w.size(); i++)
	{
		if (!w[i].empty())
		{
			for (int x : w[i]) {
				sorted.push_back(x);
			}
		}
	}

	return sorted;
}

/*
 * Function: findMax
 * Find the maximum value in a vector
 * @param v: the vector to search
 * @return: the maximum value in the vector
 */
int findMax(vector<int> v)
{
	int max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
	}

	return max;
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
		output += to_string(vector[i]);
		if (i != vector.size() - 1)
		{
			output += ", ";
		}
	}
	output += "}";

	return output;
}
