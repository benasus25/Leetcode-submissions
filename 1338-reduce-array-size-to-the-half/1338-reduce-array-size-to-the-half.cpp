class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &u:arr){
            mp[u]++;
        }
        int count  =0, n = (arr.size()+1)/2, curr = 0;
        vector<int>res;
        for(auto &[u,v]:mp){
            res.push_back(v);
        }
        sort(res.begin(),res.end(),greater<int>());
        for(auto &u:res){
            curr+=u;
            count++;
            if(curr>=n)return count;
        }
        return count;
    }
};