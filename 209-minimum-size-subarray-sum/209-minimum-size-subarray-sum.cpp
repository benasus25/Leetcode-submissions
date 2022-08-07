class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),i=0,j=0,sum=0,len = INT_MAX;
        while(j<n){
            sum+= nums[j++];
            while(sum>=target){
                len = min(len, j-i);
                sum-=nums[i++];
            }
        }
        return (len==INT_MAX)?0:len;
    }
};