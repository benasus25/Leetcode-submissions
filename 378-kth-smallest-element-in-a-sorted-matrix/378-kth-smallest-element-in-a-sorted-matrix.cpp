class Solution {
public:
    
    int solve(vector<vector<int>>&matrix, int mid){
        int n = matrix.size(), m = matrix[0].size();
        int i=n-1,j=0,count = 0;
        while(i>=0&&j<m){
            if(matrix[i][j]>mid)i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),m = matrix[0].size();
        int l= matrix[0][0], h = matrix[n-1][m-1], mid;
        while(l<h){
            mid = l+(h-l)/2;
            int val = solve(matrix,mid);
            if(val<k)l=mid+1;
            else h=mid;
        }
        return l;
    }
};