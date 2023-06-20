class Solution {
public:
    
    string correct(string s){
        string r = "";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i]))r+=tolower(s[i]);
        }
        return r;
    }
    
    bool check(string s){
        int i=0,j= s.length()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string r = correct(s);
        cout<<r<<endl;
        return check(r);
    }
};