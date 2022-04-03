class Solution {
public:
    
    vector<vector<int>>res;
    
    void helper(vector<int>nums,int i){
        
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        int j = nums.size();
        for (int k = i; k < j; k++) {
            if (i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            helper(nums,i+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return res;
    }
};