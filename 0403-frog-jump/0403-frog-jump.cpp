class Solution {
public:
    bool helper(int i,vector<int> &stones,int jump,vector<vector<int>> &dp,unordered_map<int,int> &um){
        if(i==stones.size()-1)
            return true;
        if(dp[i][jump]!=-1)
            return dp[i][jump];
        bool flag = false;

        for(int t = -1;t<2;t++){
            int curr = stones[i] + jump + t;
            if(curr>0 && um.find(curr)!=um.end() && um[curr]!=i){
                flag|=helper(um[curr],stones,jump+t,dp,um);
            }
        }
        return dp[i][jump] = flag;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(2010,vector<int>(2010,-1));
        unordered_map<int,int> um;
        for(int i=0;i<stones.size();i++)
            um[stones[i]] = i;
        return helper(0,stones,0,dp,um);
    }
};