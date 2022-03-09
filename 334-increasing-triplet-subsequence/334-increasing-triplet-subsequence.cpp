class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int n= nums.size();
    int one = INT_MAX, two = INT_MAX;
    for(int i =0;i<n;i++){
        if(nums[i]<one){
            one = nums[i];
        }
        else if(nums[i]>one&& nums[i]<two){
            two = nums[i];
        }
        else if(two<nums[i]){
            return true;
        }
    }
    return false;
    }
};