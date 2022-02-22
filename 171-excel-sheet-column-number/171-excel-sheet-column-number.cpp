class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res =0, n= columnTitle.length();
        for(int i=0;i<n;i++){
            res +=(columnTitle[i]-'A'+1)*pow(26,n-i-1);    
        }
        return res;
    }
};