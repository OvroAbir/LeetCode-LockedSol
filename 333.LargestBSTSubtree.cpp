int helper(TreeNode *root, int mini, int maxi, int &ans)
{
	if(root == NULL)
		return 0;
	int leftCount = helper(root->left, mini, root->val - 1, ans);
	int rightCount = helper(root->right, root->val + 1, maxi, ans);

	if(leftCount == -1 || rightCount == -1)
		return -1;
	
	int count = 0;
	if(mini <= root->val && root->val <= maxi)
		count = 1 + leftCount + rightCount;
	else
		return -1;

	if(count > ans)
		ans = count;

	return count;
}
int largestBSTSubtree(TreeNode *root)
{
	if(root == NULL)
		return 0;
	int ans = 0;
	helper(root, INT_MIN, INT_MAX, ans);
	return ans;
}