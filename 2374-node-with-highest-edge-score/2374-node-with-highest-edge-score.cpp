class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long>in(n,0);
        for(int i=0;i<n;i++){
            in[edges[i]]+=i;
        }
        int val = 0;
        for(int i =0;i<n;i++){
            if(in[i]>in[val])val = i;
        }
        return val;
    }
};