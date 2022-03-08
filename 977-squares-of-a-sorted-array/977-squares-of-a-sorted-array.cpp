class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int>res(n,0);
    int l=0,r=n-1;
    int k =n-1;
    while(l<=r){
        if(abs(nums[l])>abs(nums[r])){
            res[k--]= nums[l]*nums[l++];
        }
        else{
            res[k--]= nums[r]*nums[r--];
        }
    }
    return res;
    }
};