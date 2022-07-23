class Solution {
public:
    
    void merge(vector<int>&nums,int l, int mid, int h){
        int n = mid-l+1, m = h-mid;
        vector<int>tmp(mid-l+1);
        vector<int>tmp1(h-mid);
        
        for(int i=0;i<mid-l+1;i++){
            tmp[i] = nums[l+i];
        }
        for(int j=0;j<h-mid;j++){
            tmp1[j] = nums[mid+1+j];
        }
        int i=0,j=0,k=l;
        while(i<n && j<m){
            if(tmp[i]<=tmp1[j]){
                nums[k++] = tmp[i++];
            }
            else{
                nums[k++] = tmp1[j++];    
            }
        }
        while(i<n){
            nums[k++]=tmp[i++];
        }
        while(j<m){
            nums[k++]=tmp1[j++];
        }
    }
    
    void mergesort(vector<int> &nums,int low, int high){
        if(low>=high)return;
        int mid = low + (high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};