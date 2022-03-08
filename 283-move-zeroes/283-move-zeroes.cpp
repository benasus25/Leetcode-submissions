class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int k =0,i=0;
    for(;i<nums.size();i++){
        if(nums[i]==0){
            k++;
        }
        else{
            nums[i-k]= nums[i];
        }
    }
    for(int j = i-k;j<nums.size();j++){
        nums[j]=0;
    }   
    }
};