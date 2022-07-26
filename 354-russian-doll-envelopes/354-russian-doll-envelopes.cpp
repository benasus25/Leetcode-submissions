class Solution {
public:
    
    static bool compareval(const vector<int>&a, const vector<int>&b){
        return a[0]==b[0] ? b[1] < a[1] : a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), compareval); 
        vector<int> dp;
        for (auto& u : E) {
            int height = u[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left >= dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};
