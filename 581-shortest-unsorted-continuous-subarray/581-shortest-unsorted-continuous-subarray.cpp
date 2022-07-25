class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    start= i;
                    break;
                }
            }
            if(start!=-1)break;
        }
        for(int j=n-1;j>=0;j--){
            for(int i=j-1;i>=0;i--){
                if(nums[i]>nums[j]){
                    end=j;
                    break;
                }
            }
            if(end!=-1)break;
        }
        if(start==-1)return 0;
        return end-start+1;
    }
};