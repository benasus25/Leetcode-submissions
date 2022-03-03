class Solution {
public:
    int fun(int n){
        return ((n-1)*(n-2))/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
    int count =2,res =0;
    if(nums.size()<=2)return 0;
    int diff = nums[1]-nums[0];
    for(int i=2;i<nums.size();i++){
        if(nums[i]-nums[i-1]==diff)count++;
        else {
            if(count>=3){
                //if(diff==0)res+=count-2;
                res+=fun(count);
            }
            count=2;
            diff=nums[i]-nums[i-1];
        }
    }
    if(count>=3){
        //if(diff==0)res+=count-2;
        res+=fun(count);
    }
    return res;
    }
};