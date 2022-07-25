class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = 0, j = nums.size()-1, start =-1, end = -1;
        int low = INT_MIN, high = INT_MAX;
        while(j>=0&&i<nums.size()){
            if(nums[i]>=low)low = nums[i];
            else end = i;
            if(nums[j]<=high)high = nums[j];
            else start = j;
            j--,i++;
        }
        if(start==-1)return 0;
        return end-start+1;
    }
};