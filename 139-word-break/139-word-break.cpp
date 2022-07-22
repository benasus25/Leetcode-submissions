class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        unordered_set<string>mp(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for(auto u:mp){
            cout<<u<<endl;
        }
        for(int i=1;i<=s.length();i++){
            for(int j =0;j<i;j++){
                if(dp[j] && mp.find(s.substr(j,i-j))!=mp.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};