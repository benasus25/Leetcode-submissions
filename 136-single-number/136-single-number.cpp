class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto u:nums){
            res^=u;
        }
        return res;
    }
};