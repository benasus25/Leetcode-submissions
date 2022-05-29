class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res =0;
        vector<int>marks(n);
        for(int i=0;i<n;i++){
            for(auto &c: words[i]){
                marks[i]|=1 <<(c-'a');
            }
            for(int j=0;j<i;j++){
                if((marks[i]&marks[j])==0){
                    res = max(res,int(words[i].length()*words[j].length()));
                }
            }
        }
        return res;
    }
};