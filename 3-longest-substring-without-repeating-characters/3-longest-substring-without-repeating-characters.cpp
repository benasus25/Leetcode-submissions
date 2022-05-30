class Solution {
public:


    
int lengthOfLongestSubstring(string s) {
    vector<int>res(256,-1);
    int ans = 0, start = -1;
    for(int i=0;i<s.length();i++){
        if(res[s[i]]>start){
            start = res[s[i]];
        }
        res[s[i]]= i;
        ans = max(ans, i - start);
    }
    return ans;
    }
};