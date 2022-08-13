class Solution {
public:
    
    bool check(unordered_map<string,int>mp,string s, int len){
        for(int i=0;i<s.length();i+=len){
            string temp = s.substr(i,len);
            if(mp.find(temp)!=mp.end()){
                if(--mp[temp]==-1)return false;
            }
            else return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(), len = words[0].size(), size = len*n;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<int>res;
        for(int i=0;i+size<=s.length();i++){
            if(check(mp,s.substr(i,size),len)){
                res.push_back(i);
            }
        }
        return res;
    }
};