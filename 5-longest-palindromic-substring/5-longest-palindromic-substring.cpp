class Solution {
public:
	int dp[1005][1005];
	bool ispal(int i, int j, const string& s)
	{
		if(i >= j)
			return true;
		int& ret = dp[i][j];
		if(~ret)
			return ret;
		ret = s[i] == s[j];
		ret &= ispal(i + 1, j - 1, s);
		return ret;
	}
	string longestPalindrome(string s) {
		string ret = "";
		int ii, jj, mx = 0;
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < s.size();++i)
		{
			for(int j = s.size() - 1; j >= i; --j)
			{
				if(ispal(i, j, s))
				{
					//cerr << i << " " << j << " " << j - i + 1 <<  endl;
					if(j - i + 1 > mx)
					{
						ii = i;
						jj = j;
						mx = j - i + 1;
					}
				}
			}
		}
		for(int i = ii ; i <= jj; ++i)
			ret += s[i];
		return ret;
    }
};