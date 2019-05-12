void func(TreeNode *root, int level, int &minLevel, int &maxLevel, unordered_map<int, vector<int> > &vs)
{
	if (root == NULL)
		return;
	if (level < minLevel)
		minLevel = level;
	if (level > maxLevel)
		maxLevel = level;

	if (vs.find(level) == vs.end())
	{
		vector<int> temp;
		vs[level] = temp;
	}
	vs[level].push_back(root->val);
	func(root->left, level - 1, minLevel, maxLevel, vs);
	func(root->right, level + 1, minLevel, maxLevel, vs);
}

vector<vector<int> > verticalTraversal(TreeNode *root)
{
	vector<vector<int> > ans;
	if (root == NULL)
		return ans;

	unordered_map<int, vector<int> > vs;
	int minLevel = 0, maxLevel = 0;

	func(root, 0, minLevel, maxLevel, vs);

	for (int i = minLevel; i <= maxLevel; i++)
		ans.push_back(vs[i]);
	return ans;
}
