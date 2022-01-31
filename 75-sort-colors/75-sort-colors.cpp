class Solution {
public:
    
    void sortColors(vector<int>& nums) {
    int l =-1;
    int r= nums.size();
    for(int i =0;i<nums.size();i++){
        if(nums[i]==0)l++;
        else if(nums[i]==2)r--;
    }
    for(int i=0;i<nums.size();i++){
        if(i<=l)nums[i]=0;
        else if(i>l&&i<r)nums[i]=1;
        else if(i>=r)nums[i]=2;
    }
    }
};