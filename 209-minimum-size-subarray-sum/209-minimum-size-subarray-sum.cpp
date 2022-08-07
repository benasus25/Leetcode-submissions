class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int n = nums.size(), i=0,j=0, len = INT_MAX,temp =0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<target)return 0;
        if(sum==target)return n;
        while(i<=j&&j<n){
            while(j<n){
                temp+=nums[j];
                if(temp>=target)break;
                else j++;
                cout<<j<<"  "<<temp<<endl;
            }
            cout<<temp<<"End of j "<<endl;
            while(i<=j&&temp>=target){
                len = min(len,j-i+1);
                temp-=nums[i++];
                cout<<i<<"  "<<temp<<endl;
            }
            cout<<"End of i "<<temp<<endl;
            j++;
        }
        return len;
    }
};