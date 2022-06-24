class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n<0){
            n = abs(n);
            x = 1/x;
        }
        while(n){
            if(n%2){
                res *=x;
            }
            x*=x;
            n=n/2;
        }
        return res;
    }
};