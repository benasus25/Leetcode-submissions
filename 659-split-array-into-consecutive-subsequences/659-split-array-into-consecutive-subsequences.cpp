class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>temp,temp1;
        for(auto &u:nums)temp[u]++;
        for(auto &u:nums){
            if(temp[u]==0)continue;
            
            if(temp1[u-1]>0){
                temp[u]--;
                temp1[u-1]--;
                temp1[u]++;
            }
            else{
                if(temp[u+1]==0||temp[u+2]==0)return false;
                temp[u]--, temp[u+1]--,temp[u+2]--;
                temp1[u+2]++;
            }
        }
        return true;
    }
};