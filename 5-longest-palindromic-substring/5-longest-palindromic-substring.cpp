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
		//manchars' algorithm
		vector<int> p(s.size() + 5, 0);
		int m = p[0] = 0;
		for(int i = 1; i < (int)s.size(); ++i)
		{
			int mirror = 2 * m - i;
			mirror = mirror < 0 ? 0:mirror;
			int&curr = p[i] = p[mirror];
			curr = min(curr, m + p[m] - i);
			while(i + curr + 1 < (int)s.size() and i - curr - 1 >= 0 and s[i+curr+1] == s[i - curr - 1])curr++;

			if(p[i]+i > p[m]+m)
				m = i;
		}
		int mx = 0, st, en;
		for(int i = 1; i < (int)s.size();++i)
		{
			//cerr << i << " " <<  p[i] << endl;
			if(p[i] > mx)
			{
				mx = p[i];
				st = i - p[i];
				en = i + p[i];
			}
		}
		//cerr << st << endl;
		for(int i = st; i < en; ++i)
			if(s[i] != '|')
				ret += s[i];
		return ret;
    }
};