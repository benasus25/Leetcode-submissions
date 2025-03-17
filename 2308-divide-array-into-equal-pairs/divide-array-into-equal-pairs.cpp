class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto u: nums){
            mp[u] = mp[u]+1;
        }
        bool isEqual = true;
        for(auto u : mp) {
            if(u.second%2){
                isEqual = false;
                break;
            }
        }
        return isEqual;
    }
};