class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int m = pattern.size();
        for(int i=0;i<words.size();i++){
            string word = words[i];
            int j =0, k = 0, n = words[i].size();
            if(n!=m)continue;
            unordered_map<char,char>mp;
            while(j<m&&k<n){
                if(mp.find(pattern[j])!=mp.end()){
                    if(word[k]!=mp[pattern[j]])break;
                }
                else{
                    mp[pattern[j]] = word[k];
                }
                j++,k++;
            }
            bitset<26>visited;
            bool flag = false;
            for(auto &u:mp){
                if(visited[u.second]){
                    flag = true;
                    break;
                }
                else visited[u.second] = true;
            }
            if(k==n && !flag)ans.push_back(word);
        }
        return ans;
    }
};