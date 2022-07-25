class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i =0, j =nums.size()-1, mid = -1;
        vector<int>ans{-1,-1};
        while(i<=j){
            mid = i + (j-i)/2;
            if(nums[mid]==target){
                j = mid-1;
                ans[0]=mid;
            }
            else if(nums[mid]>target)j=mid-1;
            else i=mid+1;
        }
        i = 0,j =nums.size()-1;
        while(i<=j){
            mid = i + (j-i)/2;
            if(nums[mid]==target){
                i = mid+1;
                ans[1]=mid;
            }
            else if(nums[mid]>target)j=mid-1;
            else i=mid+1;
        }
        return ans;
    }
};