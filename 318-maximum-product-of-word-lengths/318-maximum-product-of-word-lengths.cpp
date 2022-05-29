class Solution {
public:
    
    bool issame(int i, int j, vector<vector<bool>>&dp){
        for(int it=0;it<26;it++){
            if(dp[i][it]&&dp[j][it])return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>>dp(n,vector<bool>(26,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                dp[i][words[i][j]-'a'] = true;
            }
        }
        int res= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!issame(i,j,dp)){
                    int num = words[i].length()*words[j].length();
                    res = max(res, num);
                }
            }
        }
        return res;
    }
};