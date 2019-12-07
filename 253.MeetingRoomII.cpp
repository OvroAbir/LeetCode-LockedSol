
static bool comp(vector<int> v1, vector<int> v2)
{
	if (v1[0] < v2[0])
		return true;
	if (v1[0] > v2[0])
		return false;
	return v1[1] < v2[1];

}
int minMeetingRooms(vector<vector<int> > ivals)
{
	if (ivals.size() <= 1)
		return ivals.size();
	sort(ivals.begin(), ivals.end(), comp);
	priority_queue<int, vector<int>, greater<int> > cur;

	int count = 1, maxCount = 1, end;
	cur.push(ivals[0][1]);
	end = ivals[0][1];

	for (int i = 1; i < ivals.size(); i++)
	{
		cur.push(ivals[i][1]);
		while (cur.size() > 0 && cur.top() < ivals[i][0])
		{
			cur.pop();
		}
		if(maxCount < cur.size())
			maxCount = cur.size();
	}
	return maxCount;
}