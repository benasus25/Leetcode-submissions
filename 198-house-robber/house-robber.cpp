class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp1 = 0, temp2 = nums[0];
        for(int i=1;i<n;i++){
            int num = max(temp2,temp1+nums[i]);
            temp1 = temp2;
            temp2 = num;
        }
        return temp2;
    }
};