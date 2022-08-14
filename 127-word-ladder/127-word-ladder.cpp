class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        if(s.find(endWord)==s.end())return 0;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            ans++;
            int len = q.size();
            while(len--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(temp==curr)continue;
                        if(temp==endWord)return ans+1;
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};