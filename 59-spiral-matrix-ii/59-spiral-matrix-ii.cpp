class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>res(n,vector<int>(n,0));
    int t =0,l=0,r =n-1,b=n-1;
    int num=1;
    while(t<=b&&l<=r){
        if(t<=b){
        for(int i=l;i<=r;i++){
            res[t][i]=num++;
        }
        }
        t++;
        if(l<=r){
        for(int i=t;i<=b;i++){
            res[i][r]=num++;
        }
        }
        r--;
        if(t<=b){
        for(int i=r;i>=l;i--){
            res[b][i]=num++;
        }
        }
        b--;
        if(l<=r){
        for(int i=b;i>=t;i--){
            res[i][l]=num++;
        }
        l++;
        }
    }
        return res;
    }
};