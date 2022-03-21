class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<int> res(26,0),ans;
    for(int i=0;i<s.length();i++){
        res[s[i]-'a']=i;
    }
    int start =0, end =0;
    for(int i=0;i<s.length();i++){
        end = max(end, res[s[i]-'a']);
        if(i==end){
            ans.push_back(end-start+1);
            start = i+1;
        }
    }
    return ans;
    }
};