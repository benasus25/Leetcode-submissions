class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
        if(digits.length()==0)return ans;
        queue<string>q;
        q.push("");
        while(!q.empty()){
            string r= q.front();
            q.pop();
            if(r.length()==digits.length()){
                ans.push_back(r);
            }
            else{
                for(auto u:phone[digits[r.length()]-'2']){
                    q.push(r+u);
                }
            }
        }
        return ans;
    }
};