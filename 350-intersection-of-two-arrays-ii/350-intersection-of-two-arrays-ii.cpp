class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(auto &x:nums1)
        {
            m[x]++;
        }
        for(auto &x:nums2)
        {
            if(m[x]>0)
            {
                ans.push_back(x);
                m[x]--;
            }
        }
        return ans;
    }
};