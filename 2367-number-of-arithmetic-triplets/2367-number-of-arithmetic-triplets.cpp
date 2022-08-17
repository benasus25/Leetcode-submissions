class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>mp;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-diff)!=mp.end()&&mp.find(nums[i]-2*diff)!=mp.end()){
                ans+= mp[nums[i]-diff]*mp[nums[i]-2*diff];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};