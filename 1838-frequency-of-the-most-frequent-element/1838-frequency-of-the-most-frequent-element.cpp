class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans = 1;
        for(;j<nums.size();j++){
            k+=nums[j];
            while(k<(long long)nums[j]*(j-i+1)){
                k-=nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};