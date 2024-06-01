class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i=0;i<s.length()-1;i++){
            ans +=getMod(s[i]-s[i+1]);
        }
        return ans;
    }

    int getMod(int a){
        if(a<0){
            return -1*a;
        }
        return a;
    }
};