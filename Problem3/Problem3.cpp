// Problem 1: Huffman Coding
// Description: Implement a Huffman coding algorithm.
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//


#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Tree
{
public:
	/*
	* Constructor for leaf node
	* @param w: the weight of the node
	* @param c: the character of the node
	*/
	Tree(int w, char c)
	{
		this->weight = w;
		this->c = c;
	}

	/*
	* Constructor for internal node
	* @param w: the weight of the node
	* @param t1: the left subtree
	* @param t2: the right subtree
	*/
	Tree(int w, Tree* t1, Tree* t2)
	{
		this->weight = w;
		this->left = t1;
		this->right = t2;
	}

	/*
	* Destructor
	*/
	~Tree()
	{
		delete(left);
		delete(right);
	}

	/*
	* Get the weight of the node
	* @return: the weight of the node
	*/
	int getWeight() const
	{
		return this->weight;
	}

	/*
	* Print the tree
	* Example of output:
	*	0 : a
	*	1 0 : c
	*	1 1 : b
	* @param bitString: the bitstring of the node
	*/
	void printTree(const vector<char>& bitString = vector<char>()) const
	{
		// Base Case: If it's a leaf node, print the character and its code
		if (!left && !right) {
			string bitStringStr(bitString.begin(), bitString.end());
			cout << bitStringStr << ": " << this->c << endl;
			return;
		}

		// Recursive Case: Traverse left and right subtrees
		if (left)
		{
			vector<char> temp = bitString;
			temp.push_back('0');
			left->printTree(temp);
		}
		if (right)
		{
			vector<char> temp = bitString;
			temp.push_back('1');
			right->printTree(temp);
		}
	}

private:
	Tree* left;
	Tree* right;
	int weight;
	char c;
};

struct TreeWrapper
{
	TreeWrapper()
	{
		tree = NULL;
	}

	TreeWrapper(Tree* t)
	{
		tree = t;
	}

	bool operator<(const TreeWrapper& tw) const
	{
		return tree->getWeight() > tw.tree->getWeight();
	}

	Tree* tree;
};


class HuffmanEncoder
{
	public:
		/*
		 * Constructor
		 * @param plainText: the string to encode
		 */
		HuffmanEncoder(string plainText)
		{
			this->plainText = plainText;
		}

		/*
		 * Encode the string
		 * @return: the encoded string
		 */
		void printCodes()
		{
			auto subTrees = createLeaves();
			this->huffmanTree = buildTree(subTrees);
			Tree* root = this->getRoot();
			root->printTree();
		}

		/*
		* Get the root of the tree
		* @return: the root of the 
		*/
		Tree* getRoot()
		{
			return huffmanTree.top().tree;
		}

	private:
		string plainText;
		priority_queue<TreeWrapper> huffmanTree;

		/*
		 * Create the leaves of the tree, and push them to a priority queue
		 * Note: the priority queue is sorted by the weight of the nodes
		 * But the tree is not built yet
		 * @return: a priority queue of the leaves
		 */
		priority_queue<TreeWrapper> createLeaves()
		{
			priority_queue<TreeWrapper> q;

			map<char, int> charWeights;

			// calculate frequencies
			for (char c : plainText)
			{
				charWeights[c]++;
			}

			// Create leaves and push them to the queue
			for (auto& pair : charWeights)
			{
				q.push(TreeWrapper(new Tree(pair.second, pair.first)));
			}

			return q;
		}

		/*
		 * Build the tree from the priority queue
		 * @param q: the priority queue of the leaves
		 * @return: the root of the tree
		 */
		priority_queue<TreeWrapper> buildTree(priority_queue<TreeWrapper> q)
		{
			if (q.size() == 1)
			{
				return q;
			}

			TreeWrapper t1 = q.top();
			q.pop();
			TreeWrapper t2 = q.top();
			q.pop();
			q.push(TreeWrapper(new Tree(t1.tree->getWeight() + t2.tree->getWeight(), t1.tree, t2.tree)));
			
			return buildTree(q);
		}
};


int main()
{
	HuffmanEncoder huffmanTree("AAAABBBC");
	huffmanTree.printCodes();
};
