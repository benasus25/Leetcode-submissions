class Solution {
public:
    int res[1001][2001];
    
    int helper(vector<vector<int>>&piles, int i, int k){
        if(i>=piles.size()||k<=0)return 0;
        if(res[i][k]!=-1)return res[i][k];
        
        int ans = helper(piles,i+1,k);
        int val = 0;
        for(int j=0;j<min(int(piles[i].size()),k);j++){
            val += piles[i][j];
            ans  = max(ans, val + helper(piles,i+1,k-(j+1)));
        }
        return res[i][k]= ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    memset(res,-1,sizeof(res));
    int ans = helper(piles,0,k);
    return ans;
    }
};