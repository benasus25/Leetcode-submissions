class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>sum = {{0,1}};
        int res =0,count =0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
            count += sum[res-k];
            sum[res]++;
        }
        return count;
    }
};