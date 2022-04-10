class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>res(n+1,0);
        res[0]=res[1]=0;
        for(int i=2;i<=n;i++){
            res[i]= min(res[i-1]+cost[i-1],res[i-2]+cost[i-2]);
            
        }
        return res[n];
    }
};