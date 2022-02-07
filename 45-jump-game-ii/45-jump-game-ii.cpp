class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int>res(n,INT_MAX);
    res[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=nums[i];j++){
            if(i+j<n){
                res[i+j]= min(res[i]+1,res[i+j]);
            }
        }
    }
    return res[n-1];
    }
};