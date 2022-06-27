class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum%2)return false;
        sum/=2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0)dp[i][j]= true;
                else if(i==0)dp[i][j]= false;
                else{
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                    }
                    else{
                        dp[i][j]= dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][sum];
    }
};