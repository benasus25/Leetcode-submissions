class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int sum = accumulate(c.begin(),c.begin()+k,0), j = c.size()-1;
        cout<<sum<<endl;
        int ans = sum;
        k--;
        while(k>=0){
            sum -= c[k--];
            sum += c[j--];
            ans = max(ans,sum);
        }
        return ans;
    }
};