class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for(int i=0;i<nums.size();i++){
            if(i==0)dp.push_back(nums[i]);
            else{
                auto x = lower_bound(dp.begin(),dp.end(), nums[i]) -dp.begin();
                if(x>=dp.size()){
                    dp.push_back(nums[i]);
                }
                else dp[x]=nums[i];
            }
        }
        return dp.size();
    }
};