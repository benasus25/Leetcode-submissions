class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int i = findmin(nums);
            nums[i]= nums[i]*multiplier;
        }
        return nums;
    }

    int findmin(vector<int> & nums){
        int min = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[min]){
                min=i;
            }
        }
        return min;
    }
};