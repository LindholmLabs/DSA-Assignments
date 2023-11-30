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
	void printTree(vector<char>& bitString) const
	{

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

class HuffmanTree
{
	public:
		/*
		 * Constructor
		 * @param plainText: the string to encode
		 */
		HuffmanTree(string plainText)
		{
			this->plainText = plainText;
		}

		/*
		 * Encode the string
		 * @return: the encoded string
		 */
		string encode()
		{
			auto subTrees = buildSubTrees();
			auto root = buildTree(subTrees);

			return "";
		}

	private:
		string plainText;

		priority_queue<TreeWrapper> buildSubTrees()
		{
			priority_queue<TreeWrapper> q;

			for (int i = 0; i < (int)plainText.size(); i++)
			{
				int weight = calculateWeight(plainText, plainText[i]);
				q.push(TreeWrapper(new Tree(weight, plainText[i])));
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
	HuffmanTree huffmanTree("abacabad");
	string encoded = huffmanTree.encode();
	
	cout << "The string was encoded to: " << encoded << endl;
};
