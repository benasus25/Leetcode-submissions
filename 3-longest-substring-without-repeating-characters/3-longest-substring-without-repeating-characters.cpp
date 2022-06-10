class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>res(256,-1);
        int start = -1,ans = 0;
        for(int i=0;i<s.length();i++){
            if(res[s[i]]>start){
                start=res[s[i]];
            }
            res[s[i]]=i;
            ans = max(ans,i-start);
        }
        return ans;
    }
};