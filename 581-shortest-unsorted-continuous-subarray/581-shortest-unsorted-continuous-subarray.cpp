class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr = nums;
        int start =-1, end =-1, n = nums.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=nums[i]){
                start=i;
                break;
            }
        }
        if(start==-1)return 0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]!=nums[i]){
                end=i;
                break;
            }
        }
        return end-start+1;
    }
};