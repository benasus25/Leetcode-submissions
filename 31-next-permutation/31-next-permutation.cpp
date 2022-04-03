class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int i = nums.size()-1,j=-1;
    for(;i>0;i--){
        if(nums[i]>nums[i-1]){
            j=i-1;
            break;
        }
    }
    if(j==-1)reverse(nums.begin(),nums.end());
    else{
        i=nums.size()-1;
        for(;i>=0;i--){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                reverse(nums.begin()+j+1,nums.end());
                break;
            }
        }
    }
    }
};