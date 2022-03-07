class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    for(int i =0;i<n;i++){
        int l = 0, r = matrix[i].size()-1;
        while(l<=r){
            int mid = l+(r-l)/2,res = matrix[i][mid];
            if(res==target)return true;
            if(res>target)r=mid-1;
            else l= mid+1;
        }
    }
    return false;
    }
};