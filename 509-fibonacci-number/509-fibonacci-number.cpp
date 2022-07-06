class Solution {
public:
    int fib(int n) {
    int sum = 0;
    if(n<=1) return n;
    int a =0,b =1;
    n-=1;
    while(n--){
        sum = a+b;
        a =b;
        b = sum;
    }
    return sum;
    }
};