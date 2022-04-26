class Solution {
public:
    
    vector<string>ans;
    vector<int> dx ={0,0,1,-1};
    vector<int>dy = {1,-1,0,0};
    
    class Trie{
        public:
            Trie *arr[26];
            bool isEnd = false;
    };
    
    void insert(string &word, Trie * root){
        Trie *curr = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(!curr->arr[idx]){
                curr->arr[idx] = new Trie();
            }
            curr = curr->arr[idx];
        }
        curr->isEnd = true;
        return;
    }
    
    bool isValid(vector<vector<char>>&board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='*')return false;
        return true;
    }
    
    void search(vector<vector<char>>&board,int i, int j, Trie* root, string &str){
        if(!isValid(board,i,j))return;
        int idx = board[i][j]-'a';
        if(!root->arr[idx])return;
        str.push_back(board[i][j]);
        char c= board[i][j];
        
        board[i][j]='*';
        if(root->arr[idx]->isEnd){
            ans.push_back(str);
            root->arr[idx]->isEnd = false;
        }
        for(int a=0;a<4;a++){
            int x = i + dx[a];
            int y = j+ dy[a];
            if(isValid(board,x,y)){
                search(board,x,y,root->arr[idx],str);
            }
        }
        board[i][j]=c;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0;i<words.size();i++){
            insert(words[i], root);
        }
        string str = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                search(board,i,j, root,str);
            }
        }
        return ans;
    }
};