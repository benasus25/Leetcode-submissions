class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int count =0, counter=nums[0];
    for(int i=0;i<nums.size();i++){
        count += nums[i];
        counter = max(count,counter);
        if(count<0) count =0;
    } 
        return counter;
    }
};