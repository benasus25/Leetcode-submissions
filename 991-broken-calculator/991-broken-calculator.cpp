class Solution {
public:
    int brokenCalc(int x, int y) {
        int steps =0;
        while(y>x){
            if(y%2==0){
                y/=2;    
            }
            else{
                y++;
            }
            steps++;
        }
    return steps + x-y;
    }
};