/**
*	BOJ
*	No.5639	이진 검색 트리
*	@author	peter9378
*	@date		2021.07.04
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* insert(Node* target, int value)
{
	if (target == NULL)
	{
		target = new Node();
		target->value = value;
		target->left = target->right = NULL;
	}
	else if (value <= target->value)
		target->left = insert(target->left, value);
	else
		target->right = insert(target->right, value);

	return target;
}

void postorder(Node* node)
{
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);

	cout << node->value << "\n";
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Node* root = NULL;
	int val;

	while (cin >> val)
	{
		if (val == EOF)
			break;

		root = insert(root, val);
	}

	postorder(root);

	return 0;
}
