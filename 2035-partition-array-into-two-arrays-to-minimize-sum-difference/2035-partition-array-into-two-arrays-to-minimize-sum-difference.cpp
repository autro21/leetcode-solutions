class Solution {
public:

	int minimumDifference(vector<int> &nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size()>>1;
		int ans = INT_MAX;
		vector<int> l[35], r[35];
		for (int i = 0; i < (1 << n); ++i) {
			int s = 0, s2 = 0, sz = 0;
			for (int j = 0; j < n; ++j) {
				if ((i >> j)&1) {
					s += nums[j];
					s2 += nums[j + n];
					sz++;
				}
				else{
					s -= nums[j];
					s2 -= nums[n + j];
				}
			}

			//cerr << sz << "\t" << s << "\t" << s2 << "\t|" << endl;
			l[sz].push_back(s);
			r[sz].push_back(s2);
		}
		for (auto& vec: r) {
			sort(vec.begin(), vec.end());
		}
		for(int sz = 0; sz <= n; ++sz)
		{
			for(const auto& a: l[sz])
			{
				const auto& rhs = r[n - sz];

				auto b = lower_bound(rhs.begin(), rhs.end(), -a);
				if(b != rhs.end())
				{
					ans = min(ans, abs(a + (*b)));
				}
				if(b != rhs.begin())
				{
					b--;
					ans = min(ans, abs(a + (*b)));
				}
			}
		}
		return ans;
	}
};