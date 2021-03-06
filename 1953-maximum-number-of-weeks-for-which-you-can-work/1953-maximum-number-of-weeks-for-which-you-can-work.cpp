class Solution {
public:
    # define ll long long
    long long numberOfWeeks(vector<int>& nums) {
        ll total = 0;
        total = accumulate(nums.begin(),nums.end(),total);
        ll max = *max_element(nums.begin(),nums.end());
        ll rest = total - max;
        if(max>rest)
            return 2*rest+1;
        else return total;
    }
};