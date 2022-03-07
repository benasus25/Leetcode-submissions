class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m= matrix[0].size();
    int l=0,r =m-1;
    while(l<n&&r>=0){
        if(matrix[l][r]==target)return true;
        if(matrix[l][r]>target)r--;
        else l++;
    }
    return false;
    }
};