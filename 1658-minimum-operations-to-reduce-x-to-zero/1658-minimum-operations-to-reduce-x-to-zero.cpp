class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i =0,runsum =0, len = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        sum -=x;
        if(sum==0)return nums.size();
        for(int j=0;j<nums.size();j++){
            runsum += nums[j];
            while(i<nums.size()&&runsum>sum){
                runsum -=nums[i++];
            }
            if(runsum==sum){
                len = max(len,j-i+1);
            }
        }
        if(!len)return -1;
        return nums.size()-len;
    }
};