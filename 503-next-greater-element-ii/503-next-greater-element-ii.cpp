class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        nums.push_back(nums[i]);
    }
    vector<int>sol(n,0);
    stack<int>s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty()&& s.top()<=nums[i]){
            s.pop();
        }
        if(s.empty()&&i<=n-1){
                sol[i]= -1;
        }
        else if(!s.empty()&&s.top()>nums[i]&&i<n){
            sol[i]=s.top();
        }
        s.push(nums[i]);
    }
    return sol;
    }
};