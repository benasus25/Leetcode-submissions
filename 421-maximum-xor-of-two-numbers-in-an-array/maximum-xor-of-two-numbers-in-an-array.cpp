class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = 0;
        int mask = 0;
        for(int i=31;i>=0;i--){
            mask = mask | (1<<i);
            unordered_set<int> numSet;
            for(int num:nums){
                numSet.insert(num&mask);
            }
            int tempMax = maxNum | (1<<i);
            for(auto prefix : numSet){
                if(numSet.contains(prefix^tempMax)){
                    maxNum = tempMax;
                    break;
                }
            }
        }
        return maxNum;
    }
};