class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v1(1002,0);
        vector<int> v2(1002,0);
        for(int i=0;i<nums1.size();i++)
            v1[nums1[i]]++;
        
        for(int i=0;i<nums2.size();i++)
            v2[nums2[i]]++;
        
        
        vector<int> res;
        for(int i=0;i<1002;i++){
            int tem=min(v1[i],v2[i]);
            while(tem--)
                res.push_back(i);
        }
        
        
        
        
        return res;
    }
};