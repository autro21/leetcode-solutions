class Solution {
public:
	int fr[255];
    int lengthOfLongestSubstring(string s) {
    	int p1 = 0, p2 = 0, ans = 0;
    	memset(fr, -1, sizeof(fr));
    	while(p2 < (int)s.size())
    	{
    		int ch = s[p2];
    		int id = fr[ch];

    		if((~id) and p1 <= id and id < p2)
    		{
    			p1 = id + 1;
    		}
    		//cerr << p1 << " " << p2 << endl;
    		ans = max(ans, p2 - p1 + 1);
    		fr[ch] = p2;
    		p2++;
    	}
    	return ans;
    }
};