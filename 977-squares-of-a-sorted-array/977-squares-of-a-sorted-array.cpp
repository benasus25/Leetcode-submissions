class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    vector<int>res;
    int n = nums.size();
    int j =0,i=0;
    for(;i<n;i++){
        if(nums[i]>=0){
            j=i-1;
            break;
        }
    }
    if(i==n)j=n-1;
    while(j>=0&&i<n){
        if(abs(nums[j])>=abs(nums[i])){
            res.push_back(nums[i]*nums[i++]);
        }
        else{
            res.push_back(nums[j]*nums[j--]);
        }
    }
    while(j>=0){
        res.push_back(nums[j]*nums[j--]);
    }
    while(i<n){
        res.push_back(nums[i]*nums[i++]);
    }
        return res;
    }
};