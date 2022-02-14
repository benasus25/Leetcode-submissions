class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int,int>>res;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0) res.push_back({i,j});
        }
    }
    int n=matrix.size();
    int m = matrix[0].size();
    for(auto u: res){
        for(int i=0;i<m;i++){
            matrix[u.first][i]=0;
        }
        for(int i=0;i<n;i++){
            matrix[i][u.second]=0;
        }
    }
    }
};