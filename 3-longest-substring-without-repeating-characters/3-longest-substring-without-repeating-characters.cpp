class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int p1 = 0, p2 = 0, ans = 0, cnt = 0;
    	set<char> fr;
    	while(p2 < s.size())
    	{
    		while(p2 < s.size() and !fr.count(s[p2]))
    		{
    			fr.insert(s[p2]);
    			p2++;
    			cnt++;
    		}
    		//system("sleep 1");
    		//cerr << cnt << " " << p1 << " " << p2 << " " << s[p2] << endl;
    		ans = max(ans, cnt);
    		while(p1 < s.size() and fr.count(s[p2]))
    		{
    			fr.erase(s[p1]);
    			p1++;
    			cnt--;
    		}
    	}
    	return ans;
    }
};