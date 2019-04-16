// 156. Binary Tree Upside Down

TreeNode* insertInLeftMost(TreeNode* root, TreeNode* newLeftNode, TreeNode* newRightNode)
{
	if (root == NULL)
		return NULL;

	TreeNode *temp = root;
	while (root->left != NULL)
		root = root->left;
	root->left = newLeftNode;
	root->right = newRightNode;

	return temp;
}

TreeNode* getUpsideDown(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	
	if (root->left == NULL && root->right == NULL)
		return new TreeNode(root->val);

	TreeNode* newRoot = getUpsideDown(root->left);
	newRoot = insertInLeftMost(newRoot, new TreeNode(root->right->val), new TreeNode(root->val));

	return newRoot;
}

//-> 156. Binary Tree Upside Down