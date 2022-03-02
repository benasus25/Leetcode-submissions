class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(nums[i]>0)break;
        if(i>0&&nums[i]==nums[i-1])continue;
        int j = i+1, k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum>0)k--;
            else if(sum<0)j++;
            else {
                res.push_back({nums[i],nums[j],nums[k]});
            int val = nums[j];
            while(j<k && val==nums[j])j++;
            val = nums[k];
            while(j<k && val==nums[k])k--;
            }
        }
    }
    return res;
    }
};