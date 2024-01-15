class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,pair<int,int>>mp;
        for(int i = 0;i<matches.size();i++){
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        for(auto u:mp){
            if(u.second.second ==0)ans[0].push_back(u.first);
            if(u.second.second ==1)ans[1].push_back(u.first);
        }
        return ans;
    }
};