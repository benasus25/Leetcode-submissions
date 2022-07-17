class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0;
        int j = 0;
        while(i!=s.length() or j!=t.length()){
            if(s[i]=='_') {
                i+=1;
                continue;
            }
            if(t[j]=='_'){
                j+=1;
                continue;
            } 
            if(s[i]!=t[j]) return false;
            if(s[i]=='L'){
                if(i<j) return false;
            }else{
                if(i>j) return false;
            }
            i+=1;
            j+=1;
        }
        
        for(;i<s.length();i++){
            if(s[i]=='_') continue;
            return false;
        }
        for(;j<t.length();j++){
            if(t[j]=='_') continue;
            return false;
        }
        return true;
    }
};