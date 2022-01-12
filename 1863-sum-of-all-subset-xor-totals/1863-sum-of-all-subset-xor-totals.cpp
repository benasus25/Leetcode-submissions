class Solution {
public:
    
    void helper(int i,int cur,vector<int>nums, int &res){
        if(i==nums.size()){
            res+=cur;
            return;
        }
        helper(i+1,cur,nums,res);
        cur ^=nums[i];
        helper(i+1,cur,nums,res);
        return;
    }
    
    int subsetXORSum(vector<int>& nums) {
    int res =0;
    helper(0,0,nums,res);
    return res;
    }
};