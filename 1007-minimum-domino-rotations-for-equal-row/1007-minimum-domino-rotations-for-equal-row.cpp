class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    vector<int>mp(7,0);
    for(int i=0;i<tops.size();i++){
        mp[tops[i]]++;
        mp[bottoms[i]]++;
    }
    int maxi = INT_MIN;
    int maxn = INT_MIN;
    for(int i=1;i<7;i++){
        if(mp[i]>maxi){
            maxi = mp[i];
            maxn = i;
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