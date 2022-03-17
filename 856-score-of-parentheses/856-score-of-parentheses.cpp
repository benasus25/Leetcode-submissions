class Solution {
public:
    int scoreOfParentheses(string s) {
    int ans =0, count =0;
    char prev = 'a';
    for(auto i:s){
        if(i=='(')count++;
        else{
            count--;
            if(prev=='(')ans +=pow(2,count);
        }
        prev =i;
    }
    return ans;
    }
};