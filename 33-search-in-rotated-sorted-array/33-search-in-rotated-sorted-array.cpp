class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(),i=0,j=n-1;
        while(i<=j){
            int mid = (i+(j-i)/2);
            if(nums[mid]==target)return mid;
            if(nums[mid]<=nums[j]){
                if(target<=nums[j]&& nums[mid]<=target)i = mid+1;
                else j= mid-1;
            }
            else{
                if(target>=nums[i]&&nums[mid]>=target)j=mid-1;
                else i= mid+1;
            }
        }
        return -1;
    }
};