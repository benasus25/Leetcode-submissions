class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1, mid =-1;
        vector<int>res{-1,-1};
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]==target){
                r=mid-1;
                res[0]=mid;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        l=0, r=nums.size()-1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]==target){
                l = mid+1;
                res[1]= mid;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};