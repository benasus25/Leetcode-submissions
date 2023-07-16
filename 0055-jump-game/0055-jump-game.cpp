class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i =0;
        int steps =0;
        while(i<=steps and i<nums.size()){
            steps = max(steps,i+nums[i]);
            i++;
        }
        return steps>=nums.size()-1;
    }
};