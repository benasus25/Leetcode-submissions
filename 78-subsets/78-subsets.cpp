class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>&nums, vector<int>ans,int i){
        if(i==nums.size()){
            res.push_back(ans);
            return;
        }
        dfs(nums,ans,i+1);
        ans.push_back(nums[i]);
        dfs(nums,ans,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>ans;
    dfs(nums,ans,0);
    return res;
    }
};