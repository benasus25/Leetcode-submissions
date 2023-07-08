class Solution {
public:
    
    int countsubarrs(vector<int>&nums,int goal){
        int i=0, n = nums.size(), j = 0, count = 0;
        if(goal<0)return 0;
        int sum = 0;
        for(int j=0;j<n;j++){
            sum +=nums[j];
            while(sum>goal){
                sum -= nums[i++];
            }
            count+=(j-i+1);
        }
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countsubarrs(nums,goal) - countsubarrs(nums,goal-1);
    }
};