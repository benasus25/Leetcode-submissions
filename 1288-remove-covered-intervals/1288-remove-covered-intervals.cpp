class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res =0,left =-1,right =-1;
        sort(intervals.begin(),intervals.end());
        for(auto u:intervals){
            if(u[0]>left&&u[1]>right){
                res++;
                left = u[0];
            }
            right = max(right,u[1]);
        }
        return res;
    }
};