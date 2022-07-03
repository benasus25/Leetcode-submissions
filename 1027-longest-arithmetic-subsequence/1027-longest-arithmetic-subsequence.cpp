class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(),res = 0;
        vector<vector<int>>dp(n,vector<int>(1001,1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[i]-nums[j]+500;
                dp[j][diff] = max(2,dp[i][diff]+1);
                res = max(res,dp[j][diff]);
            }
        }
        return res;
    }
};