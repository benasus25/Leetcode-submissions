class Solution {
public:
    int MOD = 1e9+7;
    
    int solve(vector<int>&locations,int curr, int fin, int fuel, vector<vector<int>>&dp){
        if(fuel<0)return 0;
        if(dp[curr][fuel]!=-1)return dp[curr][fuel];
        int ans  =0;
        if(curr==fin)ans++;
        for(int i=0;i<locations.size();i++){
            if(locations[i]!=locations[curr]){
                ans = (ans%MOD+solve(locations,i,fin, fuel-abs(locations[i]-locations[curr]),dp)%MOD)%MOD; 
            }
        }
        return dp[curr][fuel] = ans%MOD;
        
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};