#define MOD 1000000007

class Solution {
public:
    int countOrders(int n) {
    long long int res = 1;
    for(int i=2;i<=n;i++){
        res = res*(i*(2*i-1)%MOD)%MOD;
    }
    return res;
    }
};