class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string comm = strs[0];
        for(int i= 1;i<n;i++){
            int j =0;
            string res = "";
            while(j<strs[i].length()&& j<comm.length() &&strs[i][j]==comm[j]){
                res+=comm[j++];
            }
            comm = res;
            if(comm.length()==0)return "";
        }
        return comm;
    }
};