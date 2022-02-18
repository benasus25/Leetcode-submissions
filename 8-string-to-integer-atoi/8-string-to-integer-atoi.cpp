class Solution {
public:
    int myAtoi(string s) {
    if(!s.length())return 0;
    int res=0,i=0;
    while(i<s.length()&&s[i]==' '){
        i++;
    }
    int sign =1;
    if(i<s.length()&&(s[i]=='+'||s[i]=='-')){
        if(s[i]=='-')sign =-1;
        i++;
    }
    while(i<s.length()&&(s[i]-'0'>=0&&s[i]-'0'<=9)){
        if(res>INT_MAX/10||(res==INT_MAX/10&&s[i]-'0'>7)){
            if(sign==-1)return INT_MIN;
            return INT_MAX;
        }
        else{
            res = res*10 + (s[i]-'0');
        }
        i++;
    }
        return sign*res;
    }
};