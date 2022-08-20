class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int idx = 0, curr = 0, ans = 0;
        priority_queue<int>pq;
        pq.push(startFuel);
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            curr+=temp;
            if(curr>=target)return ans;
            while(idx<stations.size() and curr>=stations[idx][0]){
                pq.push(stations[idx][1]);
                idx++;
            }
            ans++;
        }
    return -1;
    }
};