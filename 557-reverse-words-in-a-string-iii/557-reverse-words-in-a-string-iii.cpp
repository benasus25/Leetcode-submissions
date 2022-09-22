class Solution {
public:
    
    
    string reverseWords(string s) {
    string ans ="",r ="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            reverse(r.begin(),r.end());
            ans+=r;
            ans+=' ';
            r="";
        }
        else{
            r+=s[i];
        }
    }
                reverse(r.begin(),r.end());
            ans+=r;
    return ans;
    }
};