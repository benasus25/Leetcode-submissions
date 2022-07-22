class Solution {
public:
    
    bool recur(string s, unordered_map<string,int>&mp, int i,vector<int>&ispossible){
        if(i>=s.length())return true;
        if(ispossible[i]!=-1)return ispossible[i];
        for(int j=i;j<s.length();j++){
            if(mp.find(s.substr(i,j-i+1))!=mp.end()){
                if(recur(s,mp,j+1,ispossible))return ispossible[i] = 1;
            }
        }
        return ispossible[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>ispossible(n,-1);
        unordered_map<string,int>mp;
        for(auto u:wordDict){
            mp[u]++;
        }
        return recur(s,mp,0,ispossible);
    }
};