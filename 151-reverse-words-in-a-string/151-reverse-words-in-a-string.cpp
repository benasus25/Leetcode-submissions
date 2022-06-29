class Solution {
public:
    string reverseWords(string s) {
        string z = "";
        vector<string>res;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')z+=s[i];
            else{
                if(z.length()!=0)res.push_back(z);
                z="";
            }
        }
        if(z.length()!=0)res.push_back(z);
        z="";
        for(int i=res.size()-1;i>=0;i--){
            z+=res[i];
            if(i!=0)z+=' ';
        }
        return z;
    }
};