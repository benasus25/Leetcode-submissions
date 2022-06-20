struct Trie{
    Trie* children[26];
    bool isEnd = true;
};



class Solution {
private:
    Trie *temp = new Trie();
    bool checknewword(string s){
        bool res = false;
        Trie *curr = temp;
        for (int i=s.length()-1;i>=0;i--){
            int c = s[i]-'a';
            if(!curr->children[c]){
                res = true;
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        return res;
    }

public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        sort(words.begin(),words.end(), [](string a, string b){return b.size()<a.size();});
        for(int i =0;i<words.size();i++){
            cout<<words[i]<<endl;
            if(checknewword(words[i])){
                res += words[i].size()+1;
            }
        }
        return res;
    }
};