class Solution {
public:
    
    void helper(vector<string>&res,string s, int i,int j, int n){
        if(i+j==2*n) {
            res.push_back(s);
            return; 
        }
        if(i<n)helper(res,s+"(",i+1,j,n);
        if(j<i)helper(res,s+")",i,j+1,n);
        return;
    }
    
    vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s="";
    helper(res,s,0,0,n);
    return res;
    }
};