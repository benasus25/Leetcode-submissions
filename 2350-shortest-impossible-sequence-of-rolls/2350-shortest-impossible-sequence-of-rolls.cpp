class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        int ans = 1;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(rolls[i]);
            if(s.size() == k){
                ans++;
                s.clear();
            }
        }
        return ans;
    }
};