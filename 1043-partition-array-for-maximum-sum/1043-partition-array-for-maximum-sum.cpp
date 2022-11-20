typedef long long ll;
class Solution {
public:
	ll dp[505];
	int solve(int i, const int& k, vector<int>& arr)
	{
		if(i >= arr.size())
			return 0;
		//cerr << i << " " << k << endl;
		ll& ret = dp[i];
		if(~ret)
			return ret;
		ll mx = 0;
		ret = 0;
		for(ll j = 0; j < k and i + j < (int)arr.size(); ++j)
		{
			mx = max(mx, 1LL*arr[i + j]);
			ret = max(ret, mx*(j+1) + solve(i + j + 1, k, arr));
		}
		return ret;
	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		memset(dp, -1, sizeof dp);
		return solve(0, k, arr);
    }
};
