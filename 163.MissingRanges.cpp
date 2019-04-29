	//163. Missing Ranges
	string getLimString(int low, int high)
	{
		if (low == high)
			return to_string(low);

		return to_string(low) + "->" + to_string(high);;
	}

	vector<string> missingRanges(vector<int> nums, int low, int high)
	{
		vector<string> ans;
		int from, to;
		string s;

		if (nums.size() <= 0)
		{
			s = getLimString(low, high);
			ans.push_back(s);
			return ans;
		}
		
		from = low;
		to = nums[0];
		if (from != to && from + 1 != to)
		{
			s = getLimString(from, to - 1);
			ans.push_back(s);
		}
		from = nums[0];

		for(int i=1;i<nums.size();i++)
		{
			to = nums[i];
			if (from == to || to == from + 1)
			{
				from = to;
				continue;
			}
			s = getLimString(from + 1, to - 1);
			ans.push_back(s);
			from = to;
		} 

		if (from != high && from + 1 != high)
		{
			s = getLimString(from + 1, high);
			ans.push_back(s);
		}

		return ans;
	}