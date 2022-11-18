class Solution {
public:
    vector<int> ret = {};
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < (int)nums.size();++i)
        {
        	int diff = target - nums[i];
        	//cerr << i << " " << diff << endl;
        	if(mp.count(diff))
        	{
        		cout << mp[diff] << " " << i << endl;
        		return {mp[diff], i};
        	}
        	mp[nums[i]] = i;
        }
        return ret;
    }
};
