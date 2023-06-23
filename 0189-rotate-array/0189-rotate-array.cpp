class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int j=0,n = nums.size();
        k=k%n;
        vector<int>extra(k);
        for(int i=n-k;i<n;i++){
            extra[j++]= nums[i];
        }
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]= extra[i];
        }
    }
};