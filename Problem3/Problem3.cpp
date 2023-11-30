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
	void printTree(vector<char>& bitString)
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

	/*
	* Print the tree as a graph
	* Example of output:
	* +-- 10
    * +-- A : 4
    * |-- 6
    * |   +-- B : 3
    * |   |-- 3
    * |   |   +-- D : 1
    * |   |   |-- C : 2
	*/
	void printGraph(const string& prefix = "", bool isLeft = true)
	{
		// Check if the current node is a leaf node
		if (!left && !right) {
			cout << prefix << (isLeft ? "+-- " : "|-- ") << this->c << " : " << weight << endl;
			return;
		}

		// If not a leaf node, print the node weight
		cout << prefix << (isLeft ? "+-- " : "|-- ") << weight << endl;

		// Construct the next level prefix
		string childPrefix = prefix + (isLeft ? "    " : "|   ");

		// Recursive calls for left and right children
		if (left)
			left->printGraph(childPrefix, true);
		if (right)
			right->printGraph(childPrefix, false);
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

/*
* Function: calculateWeight
* Calculate the weight of a string
* @param plainText: the string to calculate the weight of
* @param targetLetter: the letter to calculate the weight of
*/
int calculateWeight(string plainText, char targetLetter)
{
	int weight = 0;
	for (int i = 0; i < (int)plainText.size(); i++)
	{
		if (plainText[i] == targetLetter)
		{
			weight++;
		}
	}
	return weight;
}

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
		string encode()
		{
			auto subTrees = createLeaves();
			this->root = buildTree(subTrees);


			return "";
		}

		/*
		* Generate the bitstring for each character
		* @return: a map of characters and their bitstrings
		*/
		map<char, string> generateBitStrings()
		{
			map<char, string> bitStrings;
			vector<char> bitString;
			root.top().tree->printTree(bitString);
			return bitStrings;
		}

		/*
		* Get the root of the tree
		* @return: the root of the 
		*/
		Tree* getRoot()
		{
			return root.top().tree;
		}

	private:
		string plainText;
		priority_queue<TreeWrapper> root;

		priority_queue<TreeWrapper> createLeaves()
		{
			priority_queue<TreeWrapper> q;

			//build map of characters and their weights

			map<char, int> charWeights;
			for (int i = 0; i < (int)plainText.size(); i++)
			{
				if (charWeights.find(plainText[i]) == charWeights.end())
				{
					charWeights[plainText[i]] = calculateWeight(plainText, plainText[i]);
				}
			}

			// create leaves and push them to the queue
			for (auto it = charWeights.begin(); it != charWeights.end(); it++)
			{
				q.push(TreeWrapper(new Tree(it->second, it->first)));
			}

			return q;
		}

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
	HuffmanEncoder huffmanTree("aaaabbbc");
	string encoded = huffmanTree.encode();
	Tree* root = huffmanTree.getRoot();
	//create empty char vector
	vector<char> bitString;
	root->printTree(bitString);
	root->printGraph();
};
