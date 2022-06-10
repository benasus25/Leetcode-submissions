class Solution {
public:
    
    vector<vector<int>>res;
    
    void helper(vector<int>&candidates,int i, int sum, vector<int>ans, int target){
        if(i>=candidates.size()){
            if(sum==target)res.push_back(ans);
            return;
        }
        if(sum>target)return;
        if(sum + candidates[i] <= target){
            ans.push_back(candidates[i]);
            helper(candidates,i,sum+candidates[i],ans,target);
            ans.pop_back();
        }
        helper(candidates,i+1,sum,ans,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>ans;
    helper(candidates,0,0, ans, target);
    return res;
    }
};