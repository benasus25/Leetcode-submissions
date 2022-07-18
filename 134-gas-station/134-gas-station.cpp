class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start= 0, cuurg = 0, currc = 0;
        for(int i=0;i<cost.size();i++){
            cuurg+=gas[i]-cost[i];
            currc += gas[i]-cost[i];
            if(currc<0){
                start=i+1;
                currc=0;
            }
        }
        return cuurg<0?-1:start;
    }
};