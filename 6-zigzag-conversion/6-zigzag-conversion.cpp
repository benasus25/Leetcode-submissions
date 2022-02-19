class Solution {
public:
    string convert(string s, int numRows) {
    string r ="";
    int i =0,n=s.length();
    vector<string>temp(min(numRows,n),"");
    while(i<n){
        for(int j =0;j<numRows&&i<n;i++, j++)temp[j]+=s[i];
        for(int j =numRows-2;j>0&&i<n;i++, j--)temp[j]+=s[i];
    }
    for(auto u:temp)r+=u;
    return r;
    }
};