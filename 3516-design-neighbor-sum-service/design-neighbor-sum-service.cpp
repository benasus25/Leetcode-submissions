class NeighborSum {
public:
    unordered_map<int, int> adjacent;
    unordered_map<int, int> diagonal;
    NeighborSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int value = grid[i][j];
                adjacent[value] += (i - 1 >= 0 ? grid[i - 1][j] : 0);
                adjacent[value] += (i + 1 <  m ? grid[i + 1][j] : 0);
                adjacent[value] += (j - 1 >= 0 ? grid[i][j - 1] : 0);
                adjacent[value] += (j + 1 <  n ? grid[i][j + 1] : 0);

                diagonal[value] += (i + 1 <  m && j + 1 <  n ? grid[i + 1][j + 1] : 0);
                diagonal[value] += (i + 1 <  m && j - 1 >= 0 ? grid[i + 1][j - 1] : 0);
                diagonal[value] += (i - 1 >= 0 && j - 1 >= 0 ? grid[i - 1][j - 1] : 0);
                diagonal[value] += (i - 1 >= 0 && j + 1 <  n ? grid[i - 1][j + 1] : 0);
            }    
    }
    
    int adjacentSum(int value) {
        return adjacent[value];        
    }
    
    int diagonalSum(int value) {
        return diagonal[value];         
    }
};