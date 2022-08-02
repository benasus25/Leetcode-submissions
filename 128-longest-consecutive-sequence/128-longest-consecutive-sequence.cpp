class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0,count= 0;
        for(auto &u:nums){
            if(s.count(u-1))continue;
            else{
                count=1;
                while(s.count(u+count)){
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};