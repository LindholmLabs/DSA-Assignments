// Problem 3: Huffman Coding
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
	void printTree(const string& bitString = "") const
	{
		if (!left && !right) {
			cout << bitString << ": " << c << endl;
			return;
		}

		if (left) left->printTree(bitString + "0");
		if (right) right->printTree(bitString + "1");
	}

	/*
	* Construct a map of the characters and their codes
	* Since codes is passed as a reference, it will be modified
	* @param codes: the map to construct
	* @param bitString: the bitstring of the node
	*/
	void constructMap(map<char, string>& codes, const string& bitString = "")
	{
		if (!left && !right) {
			codes[c] = bitString;
			return;
		}

		if (left) left->constructMap(codes, bitString + "0");
		if (right) right->constructMap(codes, bitString + "1");
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
	* Get the codes of the characters
	* @return: a map of the characters and their codes
	*/
	map<char, string> getCodes()
	{
		auto subTrees = createLeaves();
		this->huffmanTree = buildTree(subTrees);
		Tree* root = this->getRoot();
		map<char, string> codes;
		root->constructMap(codes);
		return codes;
	}

	/*
	* Encode the string
	* @return: the encoded string
	*/
	string encode()
	{
		auto codes = getCodes();
		string encodedString = "";
		for (char c : plainText)
		{
			encodedString += codes[c];
			encodedString += " ";
		}
		return encodedString;
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
	string unEncodedString = "AAAABBBCCCCCCCCCCCCCCCCCCCCCCCCCCCD";
	HuffmanEncoder huffmanTree(unEncodedString);
	huffmanTree.printCodes();

	string encodedString = huffmanTree.encode();
	printf("Encoded string: %s\n", encodedString.c_str());

	int unEncodedLen = (int)(unEncodedString.length()*8);
	int encodedLen = (int)encodedString.length();
	
	printf("Unencoded length: %d\n", unEncodedLen);
	printf("Encoded length: %d\n", encodedLen);
	printf("saved %d bits\n", unEncodedLen - encodedLen);

	return 0;
};
