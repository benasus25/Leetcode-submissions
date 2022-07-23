class BIT{
private:
    int n;
    vector<int>tree;
public:
    BIT(int n){
        this->n = n;
        tree.resize(n+1,0);
    }
    void update(int x, int value){
        for(;x<n;x+= x&(-x)){
            tree[x] +=value;
        }
    }
    int query(int x){
        int sum = 0;
        for(;x>0;x-=x&(-x)){
            sum += tree[x];
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int min_ele = abs(*min_element(nums.begin(),nums.end()));
        for(int &u:nums){
            u+=min_ele+1;
        }
        int maxi = abs(*max_element(nums.begin(),nums.end()));
        BIT res (maxi+1);
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            ans[i] = res.query(nums[i]-1);
            res.update(nums[i],1);
        }
        return ans;
    }
};