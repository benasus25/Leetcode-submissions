class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    if(!n||!m)return false;
    int l=0,r=n-1;
    while(l<r){
        int mid = l +(r-l)/2;
        if(matrix[mid][m-1]<target)l = mid+1;
        else if(matrix[mid][0]>target)r= mid-1;
        else {
            l = mid;
            break;
        }
    }
    int i=0,j=m-1;
    while(i<=j){
        int mid =i+(j-i)/2;
        if(target>matrix[l][mid])i=mid+1;
        else if(matrix[l][mid]>target)j= mid-1;
        else return true;     
    }
        return false;
    }
};