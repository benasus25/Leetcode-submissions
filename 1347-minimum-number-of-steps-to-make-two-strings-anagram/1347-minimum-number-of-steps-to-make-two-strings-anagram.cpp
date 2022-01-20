class Solution {
public:
    int minSteps(string s, string t) {
    map<char,int>m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
        m[t[i]]--;
    }
    float sum =0;
    for(auto p:m){
        sum+= abs(p.second);
    }
    return ceil(sum/2);
    }
};