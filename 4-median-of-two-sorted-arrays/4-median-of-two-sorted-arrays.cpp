class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> vec;
    	int p1 = 0,p2 = 0;
    	while(p1 < nums1.size() and p2 < nums2.size())
    	{
    		if(nums1[p1] <= nums2[p2])
    		{
    			vec.push_back(nums1[p1++]);
    		}
    		else{
    			vec.push_back(nums2[p2++]);
    		}
    	}
    	while(p1 < nums1.size())
    	{
    		vec.push_back(nums1[p1++]);
    	}
      	while(p2 < nums2.size())
        	{
        		vec.push_back(nums2[p2++]);
        	}
//    	for(auto vl: vec)
//    		cout << vl << endl;
    	int mid = vec.size()/2 - (!(vec.size()&1));
    	double ans = vec[mid];
    	//cerr << mid << " " << ans;
    	if(!(vec.size()&1))
    	{
    		ans += vec[mid + 1];
    		ans /= 2.0;
    		//cerr << " " << vec[mid + 1];
    	}
    	//cerr << endl;
    	return ans;
   }
};