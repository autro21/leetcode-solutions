class Solution {
public:
	void converter(string& s)
	{
		string tmp = "|";
		for(auto ch: s)
		{
			tmp += ch;
			tmp += '|';
		}
		s = tmp;
	}
	string longestPalindrome(string s) {
		string ret = "";
		converter(s);

		int i, j, mx = 0;
		for(int c = 0; c < (int)s.size(); ++c)
		{
			int r = 0;
			while(c - (r + 1) >= 0 and c + (r + 1) and s[c - (r + 1)] == s[c + (r + 1)])
			{
				r++;
			}
			int sz = r*2 + 1;
			if(sz > mx)
			{
				i = c - r;
				j = c + r;
				mx = sz;
			}
		}
		for(int ii  = i ; ii <= j; ++ii)
			if(s[ii] != '|')ret += s[ii];
		return ret;
    }
};