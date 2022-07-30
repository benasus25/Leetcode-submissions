class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>mappings(26);
        for(int i=0;i<s.length();i++){
            mappings[s[i]-'a'].push_back(i);
        }
        int ans  = 0;
        for(auto &u:words){
            bool flag = true;
            int prev = -1;
            for(int i=0;i<u.length() &&flag;i++){
                auto &v = mappings[u[i]-'a'];
                auto it = upper_bound(v.begin(),v.end(),prev);
                if(it==v.end())flag = false;
                else prev= *it;
            }
            ans+=flag;
        }
        return ans;
    }
};