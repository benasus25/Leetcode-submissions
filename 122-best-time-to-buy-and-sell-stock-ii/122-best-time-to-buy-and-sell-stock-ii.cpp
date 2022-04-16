class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>s;
        int n = prices.size(),res =0;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(prices[i]);
            }
            else if(s.top()>prices[i]){
                s.push(prices[i]);
            }else{
                res+=prices[i];
                res-=s.top();
                s.pop();
                s.push(prices[i]);
            }
        }
        return res;
    }
};