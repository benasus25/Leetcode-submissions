class Solution {
public:
    
    bool helper(vector<int>&nums,vector<bool>&vis, int sum, int target, int i, int k){
        if(k==1)return true;
        if(i>=nums.size())return false;
        if(target==sum)return helper(nums,vis,sum,0,0,k-1);
        
        for(int j=i;j<nums.size()-1;j++){
            if(vis[j]||nums[j]+target>sum)continue;
            vis[j]=true;
            if(helper(nums,vis,sum,target+nums[j],j+1,k))return true;
            vis[j]=false;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k || nums.size()<k) return false;
        vector<bool>visited(nums.size(),false);
        return helper(nums,visited,sum/k,0,0,k);
    }
};