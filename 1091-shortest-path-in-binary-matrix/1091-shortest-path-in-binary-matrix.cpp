class Solution {
public:
    
    bool isvalid(int i, int j, int n, int m){
        if(i>=n||j>=m||i<0||j<0)return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]||grid[n-1][m-1])return -1;
        vector<pair<int,int>>dir = {{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{-1,0},{1,0}};
        
        queue<pair<int,int>>q;
        grid[0][0]=1;
        q.push({0,0});
        while(q.size()){
            auto ptr = q.front();
            q.pop();
            int row = ptr.first, col = ptr.second;
            if(row==n-1&&col==m-1)return grid[row][col];
            for(int i=0;i<8;i++){
                int x = row+dir[i].first;
                int y = col+dir[i].second;
                if(isvalid(x,y,n,m)&&grid[x][y]==0){
                    grid[x][y]=grid[row][col]+1;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};