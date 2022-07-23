class Solution {
public:
    
    int partition(vector<int>&nums, int low, int high){
        int pivot = rand()%(high-low+1) + low;
        swap(nums[pivot],nums[low]);
        int count  =0;
        for(int i=low+1;i<=high;i++){
            if(nums[i]<nums[low])count++;
        }
        swap(nums[low],nums[low+count]);
        pivot = low+count;
        while(low<pivot && high>pivot){
            while(nums[low]<nums[pivot])low++;
            while(nums[high]>=nums[pivot])high--;
            if(low<pivot && high>pivot){
                swap(nums[low],nums[high]);
                low++, high--;
            }
        }
        return pivot;
    }
    
    void quicksort(vector<int> &nums, int low, int high){
        if(low>=high)return;
        int pivot = partition(nums,low,high);
        quicksort(nums,low,pivot);
        quicksort(nums,pivot+1,high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};