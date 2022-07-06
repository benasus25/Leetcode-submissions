class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), i =0;
        if(n<=1)return strs[0];
        sort(strs.begin(),strs.end());
        string temp = strs[0], temp1 = strs[n-1];
        string res =  "";
        while(i<temp.length()&&temp[i]==temp1[i]){
            res += temp[i++];
        }
        return res;
    }
};