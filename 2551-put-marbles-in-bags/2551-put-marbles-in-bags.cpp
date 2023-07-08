class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n==k)return 0;
        long long maxi = 0, mini =0;
        vector<long long>res;
        for(int i=0;i<n-1;i++){
            res.push_back(weights[i]+weights[i+1]);
        }
        sort(res.begin(),res.end());
        for(int i=0;i<k-1;i++){
            maxi+= res[n-i-2];
            mini+= res[i];
        }
        return maxi-mini;
    }
};