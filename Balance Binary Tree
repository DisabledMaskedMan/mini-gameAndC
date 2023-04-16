#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int Left_Tree_Depth = maxDepth(root->left);
	int	right_Tree_Depth = maxDepth(root->right);

	return Left_Tree_Depth > right_Tree_Depth ? Left_Tree_Depth + 1 : right_Tree_Depth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int Left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return abs(Left - right) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

void TreeDestroy(struct TreeNode* root)
{
	if (root == NULL)
		return;

	TreeDestroy(root->left);
	TreeDestroy(root->right);

	free(root);
	root = NULL;
}
