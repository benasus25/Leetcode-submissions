struct TrieNode {
    TrieNode *branch[26];
    bool isEmpty = true;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& W) {
        TrieNode *trie = new TrieNode();
        int ans = 1;
        for (string word : W) {
            TrieNode *curr = trie;
            bool newWord = false;
            for (int i = word.size() - 1; i >= 0; i--) {
                int c = word[i] - 97;
                if (curr->isEmpty && !newWord) ans -= word.size() - i;
                if (!curr->branch[c]) {
                    newWord = true;
                    curr->branch[c] = new TrieNode();
                    curr->isEmpty = false;
                }
                curr = curr->branch[c];
            }
            if (newWord) ans += word.size() + 1;
        }
        return ans;
    }
};