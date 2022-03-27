typedef pair<int,int> pi;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pi>pq;
        int n = mat.size(),m= mat[0].size();
        for(int i =0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                if(!mat[i][j])break;
                sum+=1;
            }
            if(pq.size()<k){
                pq.push({sum,i});
                cout<<sum<<" "<<i<<endl;
            }
            else{
                int num = pq.top().first;
                if(num>sum){
                    pq.pop();
                    pq.push({sum,i});
                    cout<<sum<<" "<<i<<endl;
                }
            }
        }
    vector<int>ans(k--);
    while(pq.size()){
        ans[k--] = pq.top().second;
        pq.pop();
    }
    return ans;
    }
};