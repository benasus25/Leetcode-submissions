class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto u:nums){
            pq.push(u);
        }
        int num = pq.top();
        while(k--){
            num = pq.top();
            pq.pop();
        }
        return num;
    }
};