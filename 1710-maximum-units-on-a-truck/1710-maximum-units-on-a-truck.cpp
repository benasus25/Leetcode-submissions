class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int t) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0, sub =0;
        for(int i=0;i<boxTypes.size() && t>0;i++){
            sub = min(t,boxTypes[i][0]);
            ans += sub*boxTypes[i][1];
            t-=sub;
        }
        return ans;
    }
};