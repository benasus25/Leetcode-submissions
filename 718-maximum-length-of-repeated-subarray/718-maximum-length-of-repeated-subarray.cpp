class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int>dp(m+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            vector<int>dp2(m+1,0);
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp2[j] = dp[j-1]+1;
                }
                else dp2[j]= 0;
                ans = max(ans,dp2[j]);
            }
            dp = dp2;
        }
        return ans;
    }
};