class Solution {
public:
    int minimumChairs(string s) {
        int count = 0;
        int maxi = 0;
        for(int i=0;i<s.length();i++){
            count += s[i]=='E'?1:-1;
            maxi = max(maxi,count);
        }
        return maxi;
    }
};