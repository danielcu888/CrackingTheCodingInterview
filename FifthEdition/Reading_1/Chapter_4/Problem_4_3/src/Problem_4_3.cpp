#include <cmath>
#include <vector>

using namespace std;

int num_levels(int l)
{
	if(l == 0) return -1;
	double n = 0.0;
	while(l > 0)
		l -= pow(2.0, n++);
	return n;
}

int remainder(int l)
{
	if(l == 0) return -1;
	double n = 0.0;
	while(l > 0)
		l -= pow(2.0, n++);
	if(n == 1) return 0;
	else
		return l + pow(2.0, n-1);
}

struct Node
{
	Node(int _data = 0, Node *_left = 0, Node *_right = 0)
	: data(_data), left(_left), right(_right)
	{}

	Node *left, *right;
	int data;
	bool isInit = false;
};

size_t getNext(const vector<bool>& used)
{
	size_t idx = 0;
	while(used[idx])
		++idx;
	return idx;
}

void BuildTreeStruct(Node*& curr, int level, const int max, const int rem, int& count)
{
	if(curr) return;
	if(max != level)
	{
		curr = new Node();
		BuildTreeStruct(curr->left, level + 1, max, rem, count);
		BuildTreeStruct(curr->right, level + 1, max, rem, count);
		return;
	}
	else if(count != rem)
	{
		++count; //increase number times hit last level
		curr = new Node();
		return;
	}
}

bool isLeaf(Node *n)
{
	if(!n->left && !n->right) return true;
	return false;
}

void PopulateTree(Node* curr, const vector<int>& nums, vector<bool>& used, bool& writeVal, bool& writeOnceOnly)
{
	if(!curr) return;
	PopulateTree(curr->left, nums, used, writeVal, writeOnceOnly); //immediately returns if curr is a leaf
	if(isLeaf(curr))
	{
		//writeVal to current Node
		writeVal = !writeVal;
		writeOnceOnly = true;
	}
	else if(writeVal && !curr->isInit)
	{
		//writeVal to current Node
		curr->isInit = true;
	}
	else if(writeOnceOnly && !writeVal && !curr->isInit)
	{
		//writeVal to current Node
		curr->isInit = true;
		writeOnceOnly = false;
	}

	PopulateTree(curr->right, nums, used, writeVal, writeOnceOnly); //immediately returns if curr is a leaf



}

Node* warpper(const vector<int>& nums, int l)
{
	int max = num_levels(l);
	int rem = remainder(l);
	int count = 0;
	Node *head = 0;
	BuildTreeStruct(head, 1, max, rem, count);

	bool writeVal = false, writeOnceOnly = false;
	vector<bool> used(l, false);
	PopulateTree(head, nums, used, writeVal);
	return head;
}

int main()
{
	return 0;
}
