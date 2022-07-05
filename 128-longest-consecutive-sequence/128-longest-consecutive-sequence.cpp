class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest =0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end())continue;
            else{
                int count = 0, elem = nums[i];
                while(s.find(elem)!=s.end()){
                    count++;
                    elem++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};