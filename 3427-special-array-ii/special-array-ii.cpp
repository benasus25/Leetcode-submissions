class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix(n,0);
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }
        vector<bool>ans;
        for(int i =0;i<queries.size();i++){
            int right = queries[i][1], left = queries[i][0];
            int countOfSpecialPairs = prefix[right] - prefix[left];
            ans.push_back(countOfSpecialPairs==0);
        }
        return ans;
    }
};