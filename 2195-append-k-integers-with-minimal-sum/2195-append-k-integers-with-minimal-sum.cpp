class Solution {
public:
    
    long long func(int a){
        long long ans = a;
        ans*=(a+1);
        ans/=2;
        return ans;
    }
    
    long long minimalKSum(vector<int>& nums, int k) {
    long long ans =0;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    bool flag = false;
    int f =0, s= 0; 
    for (auto u:mp){
        //if(flag==true)return ans;
        if(u.second>0){
            s = u.first;
            int diff = s-f-1;
            if(diff==0){
                f=s;
                continue;
            }
            if(k>=diff){
                k-=diff;
                ans += (func(s-1)-func(f));
            }
            else{
                cout<<s<<" "<<f<<endl;
                ans += (func(f+k)-func(f));
                k=0;
            }
            f=s;
            if(k==0)break;
       }
    }
    if(k>0){
        ans+=(func(s+k)-func(s));
    }
        return ans;
    }
};