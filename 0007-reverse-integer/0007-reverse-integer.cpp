class Solution {
public:
    int reverse(int x) {
        int res =0;
        while(x){
            int n = x%10;
            if(res>INT_MAX/10 or (res==INT_MAX/10 and n>7)){
                return 0;
            }
            if(res<INT_MIN/10 or (res==INT_MIN/10 and n>7))return 0;
            res= res*10+n;
            x=x/10;
        }
        return res;
    }
};