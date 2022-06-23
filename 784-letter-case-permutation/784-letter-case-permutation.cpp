class Solution {
public:
    
    void helper(vector<string>& res, string s, int i){
        if(s.length()==i){
            res.push_back(s);
            return;
        }
        if(isalpha(s[i])){
            s[i]= tolower(s[i]);
            helper(res,s,i+1);
            s[i]= toupper(s[i]);
            helper(res,s,i+1);
        }
        else{
            helper(res,s,i+1);
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        helper(res,s,0);
        return res;
    }
};