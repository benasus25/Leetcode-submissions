// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int sum = 0, len = 0;
//         unordered_map<int,int>mp;
//         mp[0] =-1;
//         for(int i=0;i<nums.size();i++){
//             sum += nums[i]==1 ?1:-1;
//             if(mp.find(sum)!=mp.end()){
//                 len = max(len, i-mp[sum]);
//             }
//             else mp[sum] = i;
//         }
//         return len;
//     }
// };
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0;
        unordered_map<int, int> seen{{0, -1}};
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};