
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

int BinarySize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return BinarySize(root->left) + BinarySize(root->right) + 1;
}

void BinaryPre(struct TreeNode* root, int* a, int* i)
{
	if (root == NULL)
		return;

	a[*i] = root->val;
	(*i)++;
	BinaryPre(root->left, a, i);
	BinaryPre(root->right, a, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int i = 0;
	int size = BinarySize(root);
	int* a = (int*)malloc(size * sizeof(int));
	BinaryPre(root, a, &i);
	*returnSize = size;
	return a;
}
