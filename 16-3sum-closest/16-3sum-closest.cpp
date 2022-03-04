class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans = nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-2;i++){
        if(i>0&&nums[i-1]==nums[i])continue;
        int j=i+1,k = nums.size()-1;
        while(j<k){
            int res= nums[i]+nums[j]+nums[k];
            if(res==target)return res;
            else if(abs(target-res)<abs(target-ans))ans=res;
            if (target>res)j++;
            else k--;
        }
    }
    return ans;
    }
};