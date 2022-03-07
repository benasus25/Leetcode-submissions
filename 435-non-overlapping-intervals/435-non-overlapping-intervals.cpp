    bool comp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comp);
    int count =0;
    int last = intervals[0][1];
    for(int i=1;i<n;i++){
        if(intervals[i][0]<last){
            count++;
        }
        else{
            last = intervals[i][1];
        }
    }
        return count;
    }
};