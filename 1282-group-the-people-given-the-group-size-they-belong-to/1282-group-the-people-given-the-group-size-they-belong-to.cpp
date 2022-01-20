class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int,vector<int>>mp;
    for(int i =0;i<groupSizes.size();i++){
        mp[groupSizes[i]].push_back(i);
    }
    vector<vector<int>>res;
    for(auto p: mp){
        int j =0;
        while(j<p.second.size()){
        vector<int>sol;    
            for(int i=0;i<p.first;i++){
                sol.push_back(p.second[i]);
                j++;
            }
        res.push_back(sol);
        }
    }
    return res;
    }
};