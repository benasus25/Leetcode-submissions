class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k) {
        int left = 0, right  = 0, ans = 1, n = nums.size();
        sort(nums.begin(),nums.end());
        while(right<n){
            k+=nums[right];
            while((1ll)*nums[right]*(right-left+1)>k){
                k-=nums[left];
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};