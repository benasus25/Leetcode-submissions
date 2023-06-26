typedef pair<int, int> pi;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans =0;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        int i=0, j =n-1;
        while(i<candidates and i<n){
            pq.push(make_pair(costs[i],i++));
            
        }
        while(j>=0 and j>=i and j>=n-candidates){
            pq.push(make_pair(costs[j],j--));
        }
        while(k--){
            ans += pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(i<=j){
                if(idx >j){
                    pq.push(make_pair(costs[j],j--));
                }
                else if(idx<i){
                    pq.push(make_pair(costs[i],i++));
                }
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};