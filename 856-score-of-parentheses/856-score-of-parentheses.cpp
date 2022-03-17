class Solution {
public:
    int scoreOfParentheses(string s) {
    int ans =0, count =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')count++;
        else{
            count--;
            if(s[i-1]=='(')ans +=pow(2,count);
        }
    }
    return ans;
    }
};