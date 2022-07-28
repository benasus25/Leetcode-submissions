class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp;
        if(s.length()!=t.length())return false;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto &u:mp){
            if(u.second!=0)return false;
            
        }
        return true;
    }
};