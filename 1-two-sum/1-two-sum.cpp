class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,int> sol;
    for(int i =0;i<nums.size();i++){
        auto p = sol.find(target-nums[i]);
        if(p!=sol.end()){
            res.push_back(i);
            res.push_back(sol[target-nums[i]]);
            return res;
        }
        sol[nums[i]]=i;
    }
        return res;
    }
};