class Solution {
public:
    bool helper(vector<int>&nums,int m,int mid){
        int sum = 0, count=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid)sum+=nums[i];
            else{
                count++;
                sum = nums[i];
                if(count>m)return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int high=0, low = INT_MIN;
        for(int i=0;i<nums.size();i++){
            high +=nums[i];
            low = max(low, nums[i]);
        }
        while(low<high){
            int mid = low + (high-low)/2;
            if(!helper(nums,m,mid)){
                low = mid+1;
            }
            else high =mid;
        }
        return low;
    }
};