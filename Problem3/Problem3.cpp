// Problem 1: Huffman Coding
// Description: Implement a Huffman coding algorithm.
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct node
{
	char data;
	int freq = 0;
	node* left = NULL;
	node* right = NULL;
};


class nodeComparator
{
	public:
		bool operator() (const node& leftNode, const node& rightNode) const
		{
			return leftNode.freq > rightNode.freq;
		}
};


/*
 * Class: HuffmanTree
 * Description: A Huffman tree
 */
class huffmanTree
{
	private:
		priority_queue<node, vector<node>, nodeComparator> nodes;

	public:
		/*
		 * Function: Constructor
		 * Description: Create a Huffman tree from a string
		 * @param plainText: the string to create the tree 
		 */
		huffmanTree(string plainText)
		{
			// create nodes 
			for (int i = 0; i < (int) plainText.length(); i++)
			{
				node n;
				n.data = plainText[i];
				n.freq += 1;
				nodes.push(n);
			}
		}
			
		/*
		 * Function: getTree
		 * Description: Get the Huffman tree
		 * @return: reference of ´the Huffman tree
		 */
		priority_queue<node, vector<node>, nodeComparator> getTree() const
		{
			return nodes;
		}

		/*
		 * Function: printTree
		 * Description: Print the Huffman tree
		 */
		void print() const
		{
			priority_queue<node, vector<node>, nodeComparator> temp = nodes;

			while (!temp.empty())
			{
				cout << temp.top().data << " " << temp.top().freq << endl;
				temp.pop();
			}
		}
};


int main()
{
	huffmanTree T = huffmanTree("Hello World");

	T.print();
};
