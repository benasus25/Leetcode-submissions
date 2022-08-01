class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,res=0,count=0,n = nums.size();
        while(j<n){
            if(nums[j]%2){
                k--;
                count =0;
            }
            while(k==0){
                if(nums[i]%2==1)k++;
                count++;
                i++;
            }
            j++;
            res+=count;
        }
        return res;
    }
};