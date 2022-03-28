class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size(),steps = nums[0],i=0;
    while(i<=steps&&i<n){
        steps = max(steps,i+nums[i]);
        i++;
    }
    return steps>=n-1;
    }
};