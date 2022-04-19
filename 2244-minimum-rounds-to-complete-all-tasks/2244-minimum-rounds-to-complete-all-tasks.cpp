class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int count = 0;
        unordered_map<int,float>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto u:mp){
            if(u.second<2)return -1;
            count += ceil(u.second/3);
        }
        return count;
    }
};