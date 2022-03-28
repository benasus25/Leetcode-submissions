class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int,int>>q;
    int n = maze.size(),m = maze[0].size(),steps =1;
    maze[entrance[0]][entrance[1]]='+';
    q.push({entrance[0],entrance[1]});
    vector<vector<int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
    while(q.size()){
        int len = q.size();
        while(len--){
            auto [i,j]= q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x = i+dir[k][0];
                int y = j+dir[k][1];
                if(x>=n||y>=m||x<0||y<0||maze[x][y]=='+')continue;
                if(x==0||y==0||x==n-1||y==m-1)return steps;
                maze[x][y]='+';
                q.push({x,y});
            }
        }
        steps++;
    }
    return -1;
    }
};