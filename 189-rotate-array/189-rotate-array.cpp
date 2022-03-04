class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    vector<int>temp(k);
    int n = nums.size(),j=0;
    k=k%n;
    for(int i=n-k;i<n;i++){
        temp[j]= nums[i];
        j++;
    }
    for(int i=n-1;i>=k;i--){
        nums[i]= nums[i-k];
    }
    for(int i=0;i<k;i++){
        nums[i]= temp[i];
    }
    }
};