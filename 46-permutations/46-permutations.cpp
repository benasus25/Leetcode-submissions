class Solution {
public:
    
    void helper(vector<vector<int>>&res, vector<int>&num, int i){
        if(i==num.size()){
            res.push_back(num);
            return;
        }
        for(int j=i;j<num.size();j++){
            swap(num[i],num[j]);
            helper(res,num,i+1);
            swap(num[i],num[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        helper(res,nums,0);
        return res;
    }
};