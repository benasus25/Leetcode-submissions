class Trienode{
public:
    bool isEnd;
    vector<Trienode*>child;
    Trienode(){
        isEnd = false;
        child.resize(26,nullptr);
    }
};

class Trie {
private:
    Trienode* root;
public:
    Trie() {
        root = new Trienode();    
    }
    
    void insert(string word) {
        Trienode* node = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(node->child[c]==NULL){
                node->child[c] = new Trienode();
            }
            node = node->child[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trienode* node = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(node->child[c]==NULL)return false;
            node = node->child[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        Trienode* node = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(node->child[c]==NULL)return false;
            node = node->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */