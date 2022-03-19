class Solution {
public:
    //vector<vector<int>>ans;
    
    void dfs(int src, vector<vector<int>>&image, int i, int j, int newColor){
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]==newColor||image[i][j]!=src){
            return;
        }
        else{
            image[i][j]= newColor;
            dfs(src,image,i+1,j,newColor);
            dfs(src,image,i-1,j,newColor);
            dfs(src,image,i,j-1,newColor);
            dfs(src,image,i,j+1,newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int src = image[sr][sc];
    dfs(src,image,sr,sc,newColor);
    return image;
    }
};