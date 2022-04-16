class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num1 = INT_MAX, num2 = prices[0],res =0;
        for(int i=0;i<prices.size();i++){
            num2 = prices[i];
            if(num2>num1){
                res+=num2-num1;
            }
            num1 = num2;
        }
        return res;
    }
};