// class Solution {
// public:
    
//     vector<vector<int>>ans;
    
//     void helper(vector<int>&res,vector<int>&nums, int i){
//         ans.push_back(res);
//         for(int j =i;j<nums.size();j++){
//             if(j>i && nums[j]==nums[j-1])continue;
//             res.push_back(nums[j]);
//             helper(res,nums,i+1);
//             res.pop_back();
//         }
//     }
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int>res;
//         helper(res,nums,0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;       //to store all susbets
        vector<int> curr;         //to store current individual subset (that we will build)
        sort(nums.begin(),nums.end());      //sort the array so that duplicates are adjacent 
        helper(nums,ans,curr,0);       //we start from index 0
        return ans;
        
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx){
        ans.push_back(curr);       //we include current susbet into final ans
        for(int i=idx;i<nums.size();i++){     //check for all possibilites
            if(i>idx &&  nums[i]==nums[i-1]) continue;      //if duplicate then we continue
            curr.push_back(nums[i]);     //we include nums[i] in current subset
            helper(nums,ans,curr,i+1); 
            curr.pop_back();         //to get subset without nums[i]
        }
    }  
};