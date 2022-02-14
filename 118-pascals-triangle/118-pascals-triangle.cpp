class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>>sol;
        vector<int>res;
        res.push_back(1);
        sol.push_back(res);
    for(int i =1;i<numRows;i++){
        vector<int>res;
        res.push_back(1);
        for(int j=1;j<i;j++){
            res.push_back(sol[i-1][j-1]+sol[i-1][j]);
        }
        res.push_back(1);
        sol.push_back(res);
    }
        return sol;
    }
};