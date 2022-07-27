class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int left = 1, res = 0;
        int right = *max_element(q.begin(),q.end());
        while(left<=right){
            int mid = left+(right-left)/2, count = 0;
            for(auto &u:q)count += (u+mid-1)/mid;
            if(count<=n){
                res = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};