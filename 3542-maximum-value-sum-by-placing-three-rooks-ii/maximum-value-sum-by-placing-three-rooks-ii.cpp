class Solution {
public:
  long long maximumValueSum(vector<vector<int>>& board) {
    int y = board.size(), x = board[0].size(); 
    vector<vector<int>> t(y*x);

    for(int i = 0, k = 0; i != y; i++)
      for(int j = 0; j != x; j++, k++) t[k] = {board[i][j], i, j};

    sort(t.begin(), t.end(), [](const vector<int> &a,const vector<int> &b)->bool {return a[0] < b[0];});

    long ans = LONG_MIN; 
    for(int a = t.size() - 1; a != 1; a--)
      if(ans >= (long)t[a][0] * 3) break;
      else
        for(int b = a-1; b > 0; b--)
          if(t[a][1] == t[b][1] || t[a][2] == t[b][2]) continue;
          else
            if(ans >= (long)t[a][0] + t[b][0]*2) break;
            else
              for(int c = b-1; c >= 0; c--)
                if(t[a][1] == t[c][1] || t[a][2] == t[c][2] || t[c][1] == t[b][1] || t[c][2] == t[b][2]) continue;
                else{
                  if(ans < (long)t[a][0] + t[b][0] + t[c][0]) ans = (long)t[a][0] + t[b][0] + t[c][0];
                  break;
                }
          
    return ans; 
  }
};