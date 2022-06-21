class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), i =0;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(i<n-1 && pq.size()<ladders){
            int diff = heights[i+1]-heights[i];
            if(diff>0){
                pq.push(diff);
            }
            i++;
        }
        while(i<n-1){
            int diff = heights[i+1]-heights[i];
            if(diff>0){
                if(!pq.empty() && diff>pq.top()){
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(diff);
                }
                else{
                    bricks -= diff;
                }
            }
            if(bricks<0)return i;
            i++;
        }
        return i;
    }
};