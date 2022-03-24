class Solution {
public:
    int findMin(vector<int>& nums) {
    int n = nums.size();
    int i=0,j=nums.size()-1;
    while(i<j){
        int mid = i +(j-i)/2;
        int prev = (mid+n-1)%n;
        int next = (mid+1)%n;
        if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next]){
            return nums[mid];
        }
        else if(nums[mid]>nums[j])i= mid+1;
        else j = mid-1;
    }
    return nums[j];
    }
};