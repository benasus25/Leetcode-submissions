class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>>W(17);
        for(auto word:words){
            W[word.size()].insert(word);
        }
        int res = 1;
        unordered_map<string,int>dp;
        for(int i=16;i;i--){
            if(W[i-1].size()==0)continue;
            for(auto word:W[i]){
                int val = dp[word]?dp[word]:1;
                for(int j = 0;j<word.size();j++){
                    string temp = word.substr(0,j)+ word.substr(j+1);
                    int val1 = dp[temp]?dp[temp]:1;
                    if(W[i-1].find(temp)!=W[i-1].end()&& val>=val1){
                        dp[temp]= val+1;
                        res = max(res,val+1);
                    }
                }
            }
        }
        return res;
    }
};