class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    unordered_map<int,int>mp;
    for(int i=0;i<tops.size();i++){
        mp[tops[i]]++;
        mp[bottoms[i]]++;
    }
    int maxi = INT_MIN;
    int maxn = INT_MIN;
    for(auto u:mp){
        if(u.second>maxi){
            maxi = u.second;
            maxn = u.first;
        }
    }
    int count =0,cnt =0;
    for(int i=0;i<tops.size();i++){
        if(tops[i]!=maxn){
            if(bottoms[i]==maxn)count++;
            else{
                return -1;
            }
        }
    }
    for(int i=0;i<tops.size();i++){
        if(bottoms[i]!=maxn){
            if(tops[i]==maxn)cnt++;
            else{
                return -1;
            }
        }
    }
    return min(count, cnt);
    }
};