class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int>sol(n,0);
    sol[0]= prices[0];
    for(int i =1;i<n;i++){
        sol[i]= min(sol[i-1],prices[i]);
    }
    int res = 0;
    for(int i=1;i<n;i++){
        res = max(res, prices[i]-sol[i]);
    }
        return res;
    }
};