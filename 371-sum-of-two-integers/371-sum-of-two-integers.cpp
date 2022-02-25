class Solution {
public:
    int getSum(int a, int b) {
    int count =0;
    while(a!=0){
        if(a>0){
                a--;
                count++;
            }
        else {
                a++;
                count--;
            }
    }
    while(b!=0){
        if(b>0){
                b--;
                count++;
            }
        else {
                b++;
                count--;
            }
    }
    return count;
    }
};