class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto u:nums){
            pq.push(u);
        }
        while(k-->1){
            pq.pop();
        }
        return pq.top();
    }
};