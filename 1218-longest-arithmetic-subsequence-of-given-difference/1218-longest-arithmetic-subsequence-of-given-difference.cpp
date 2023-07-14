class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i]-diff)!=mp.end()){
                int num = mp[arr[i]-diff]+1;
                mp[arr[i]]= num;
                ans = max(ans, num);
            }
            else mp[arr[i]] =1;
        }
        return ans;
    }
};