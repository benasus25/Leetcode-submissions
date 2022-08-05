class Solution {
public:
    
    int helper(vector<int>&nums,vector<int>&res, int target){
        if(target==0)return 1;
        if(res[target]!=-1)return res[target];
        res[target]=0;
        for(auto num:nums){
            if(num<=target)res[target]+= helper(nums,res,target-num);
        }
        return res[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>res(target+1,-1);
        return helper(nums,res,target);
    }
};