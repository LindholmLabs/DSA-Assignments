// Problem 1: Bucket Sort
// Description: Sort a vector using a modified version of bucket sort.
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 13-11-2023
//


#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <tuple>

using namespace std;


// Function prototypes
vector<int> bucketSort(vector<int> unsortedVector);
vector<int> insertionSort(vector<int> unsortedVector);
string vectorToString(vector<int> vector);
int findMax(vector<int> v);
vector<int> generateRandomVector(int low, int high, int size);
void showProgressBar(int width, double progress);
void printuple(tuple<int, int, double> t);

int main()
{
	int startingSize = 1000;
	int iterations = 100;
	int arraySize = 10000;
	int stepSize = 1000;

	srand(12345);

	vector<tuple<int, int, double>> durations;

	for (int i = startingSize; i < arraySize; i += stepSize) {
		cout << "\nArray element max value: " << i << endl;
		for (int j = 1; j < iterations + 1; j++) {

			showProgressBar(100, (double)j / iterations);

			vector<int> unsorted = generateRandomVector(0, i, j * 1000);

			auto start = chrono::high_resolution_clock::now();

			vector<int> sorted = insertionSort(unsorted);

			auto end = chrono::high_resolution_clock::now();

			chrono::duration<double> elapsed = end - start;

			durations.push_back(make_tuple(i, j * 1000, elapsed.count()));
		}
	}
	
	cout << endl;

	for (tuple<int, int, double> t : durations) {
		printuple(t);
	}

	//vector<int> insertSorted = insertionSort(unsorted);
	//cout << "The unsorted vector: " << vectorToString(unsorted) << endl;
	//cout << "The sorted vector: " << vectorToString(sorted) << endl;
	//cout << "The sorted vector using InsertSort: " << vectorToString(insertSorted) << endl;

	return 0;
}


/*
 * Function: bucketSort
 * Sort an unsorted vector using a modified version of bucket sort
 * @param v: the unsorted vector
 * @return: the sorted vector
 */
vector<int> bucketSort(vector<int> v)
{
	int max = findMax(v);

	// Create buckets (each bucket is a vector)
	vector<vector<int>> w(max + 1, vector<int>());

	// Add values to buckets
	for (int i = 0; i < (int)v.size(); i++)
	{
		w[v[i]].push_back(v[i]);
	}

	// Create sorted vector
	vector<int> sorted(0);

	// Append from buckets in order to sorted vector
	for (int i = 0; i < (int)w.size(); i++)
	{
		//check if bucket is empty
		if (!w[i].empty())
		{
			// loop through each bucket
			for (int value : w[i]) {
				sorted.push_back(value);
			}
		}
	}

	return sorted;
}

/*
 * Function: insertSort
 * Sort an unsorted vector using insertionsort
 * @param v: the unsorted vector
 * @return: the sorted vector
 */
vector<int> insertionSort(vector<int> v)
{
	int i, j, key;
	for (i = 0; i < v.size(); i++)
	{
		key = v[i];
		j = i - 1;

		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
	return v;
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
	for (int i = 1; i < (int)v.size(); i++)
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
	for (int i = 0; i < (int)vector.size(); i++)
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


/*
* Function: generateRandomVector
* Generate a random vector of a given size
* @param low: the lowest possible value in the vector
* @param high: the highest possible value in the vector
* @param size: the size of the vector to generate
*/
vector<int> generateRandomVector(int low, int high, int size)
{
	vector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = rand() % (high - low + 1) + low;
	}

	return v;
}

/*
* Function: showProgressBar
* Show a progress bar in the console
* @param width: the width of the progress bar
* @param progress: the progress of the bar
*/
void showProgressBar(int width, double progress) {
	int pos = width * progress;

	cout << "[";
	for (int i = 0; i < width; ++i) {
		if (i < pos) cout << "=";
		else if (i == pos) cout << ">";
		else cout << " ";
	}
	cout << "] " << int(progress * 100.0) << " %\r";
	cout.flush(); // Important to flush the output
}

void printuple(tuple<int, int, double> t) {
	cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;
}